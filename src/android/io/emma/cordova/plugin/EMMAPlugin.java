package io.emma.cordova.plugin;

import android.content.Context;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.Color;
import android.os.Bundle;
import android.support.annotation.ColorInt;
import android.support.annotation.DrawableRes;
import android.util.Log;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import io.emma.android.EMMA;
import io.emma.android.interfaces.EMMABatchNativeAdInterface;
import io.emma.android.interfaces.EMMANativeAdInterface;
import io.emma.android.interfaces.EMMASessionStartListener;
import io.emma.android.model.EMMACampaign;
import io.emma.android.model.EMMAEventRequest;
import io.emma.android.model.EMMAInAppRequest;
import io.emma.android.model.EMMANativeAd;
import io.emma.android.model.EMMANativeAdField;
import io.emma.android.model.EMMANativeAdRequest;
import io.emma.android.model.EMMAPushOptions;
import io.emma.android.utils.EMMALog;
import io.emma.android.utils.ManifestInfo;

import static io.emma.cordova.plugin.EMMAPluginConstants.*;

public class EMMAPlugin extends CordovaPlugin {

    private boolean pushInitialized = false;
    private Map<String, EMMACampaign.Type> inAppTypesMap;

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        initInAppTypes();
    }

    @Override
    public void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        if (pushInitialized) {
            EMMA.getInstance().onNewNotification(intent, true);
        }
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        EMMALog.d("Executed method: " + action);

        Log.d("EMMA", args.getJSONObject(0).toString());

        if (action.equals("startSession")) {
            if (args.length() == 1) {
                return startSession(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("startPush")) {
            if (args.length() == 1) {
                return startPush(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("trackEvent")) {
            if (args.length() == 1) {
                return trackEvent(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("trackUserExtras")) {
            if (args.length() == 1) {
                return trackUserExtras(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("loginUser")) {
            if (args.length() == 1) {
                return loginUser(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("registerUser")) {
            if (args.length() == 1) {
                return registerUser(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("startOrder")) {
            if (args.length() == 1) {
                return startOrder(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("addProduct")) {
            if (args.length() == 1) {
                return addProduct(args.getJSONObject(0), callbackContext);
            }
        } else if (action.equals("trackOrder")) {
            return trackOrder(callbackContext);
        } else if (action.equals("cancelOrder")) {
            return cancelOrder(args, callbackContext);
        } else if (action.equals("checkForRichPush")) {
            return checkForRichPush(callbackContext);
        } else if (action.equals("inAppMessage")) {
            if (args.length() == 1) {
                return inAppMessage(args.getJSONObject(0), callbackContext);
            }
        }

        EMMALog.w(INVALID_METHOD_OR_ARGUMENTS);

        return false;
    }

    private boolean startSession(JSONObject args, final CallbackContext callbackContext) {
        Context applicationContext = cordova.getActivity().getApplicationContext();

        String sessionKey = args.optString(SESSION_KEY);
        boolean debug = args.optBoolean(DEBUG);
        EMMALog.setLevel(debug ? EMMALog.VERBOSE : EMMALog.NONE);
        boolean validSessionKey = !sessionKey.isEmpty() && !sessionKey.trim().equals("");

        if (!validSessionKey && !sessionKeyInMetadata(applicationContext)) {
            String msg = "";
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        EMMA.Configuration.Builder configuration =
                new EMMA.Configuration.Builder(applicationContext)
                        .setDebugActive(debug);

        if (validSessionKey) {
            configuration.setSessionKey(sessionKey);
        }

        int queueTime = args.optInt(QUEUE_TIME);
        if (queueTime >= MIN_QUEUE_TIME) {
            configuration.setQueueTime(queueTime);
        }

        String apiUrl = args.optString(API_URL);
        if (!apiUrl.trim().equals("")) {
            configuration.setWebServiceUrl(apiUrl);
        }

        JSONArray customPowlinkDomains = args.optJSONArray(CUSTOM_POWLINK_DOMAINS);
        if (customPowlinkDomains != null) {
            List<String> parsedDomains =
                    arrayToStringList(CUSTOM_POWLINK_DOMAINS, customPowlinkDomains);
            if (parsedDomains.size() > 0) {
                configuration.setPowlinkDomains((String[]) parsedDomains.toArray());
            }
        }

        JSONArray customShortPowlinkDomains = args.optJSONArray(CUSTOM_SHORT_POWLINK_DOMAINS);
        if (customShortPowlinkDomains != null) {
            List<String> parsedDomains =
                    arrayToStringList(CUSTOM_SHORT_POWLINK_DOMAINS, customShortPowlinkDomains);
            if (parsedDomains.size() > 0) {
                configuration.setPowlinkDomains((String[]) parsedDomains.toArray());
            }
        }

        configuration.trackScreenEvents(args.optBoolean(TRACK_SCREEN_EVENTS, true));

        EMMA.getInstance().startSession(configuration.build(), new EMMASessionStartListener() {
            @Override
            public void onSessionStarted() {
                callbackContext.success();
            }
        });

        return true;
    }

    private boolean startPush(JSONObject args, final CallbackContext callbackContext) {
        Context context = cordova.getContext().getApplicationContext();

        Class clazz;
        try {
            clazz = Class.forName(args.optString(PUSH_CLASS_TO_OPEN));
        } catch (ClassNotFoundException ex) {
            EMMALog.e(PUSH_CLASS_MANDATORY);
            callbackContext.error(PUSH_CLASS_MANDATORY);
            return false;
        }

        int notificationIcon = 0;
        String notificationIconName = args.optString(PUSH_ICON_RESOURCE);
        if (!notificationIconName.trim().equals("")) {
            notificationIcon = getNotificationIcon(context, notificationIconName);
        }

        EMMALog.d("Notification icon" + notificationIcon);

        if (notificationIcon == 0) {
            EMMALog.e(PUSH_NOTIFICATION_DRAWABLE_MANDATORY);
            callbackContext.error(PUSH_NOTIFICATION_DRAWABLE_MANDATORY);
            return false;
        }

        EMMAPushOptions.Builder pushOptions = new EMMAPushOptions.Builder(clazz, notificationIcon);

        String hexaColor = args.optString(PUSH_NOTIFICATION_COLOR);
        if (!hexaColor.trim().equals("")) {
            try {
                int colorInt = getNotificationColor(hexaColor);
                pushOptions.setNotificationColor(colorInt);
            } catch (IllegalArgumentException ex) {
                EMMALog.e(PUSH_NOTIFICATION_COLOR_MANDATORY);
            }
        }

        String channelId = args.optString(PUSH_NOTIFICATION_CHANNEL_ID);
        if (!channelId.trim().equals("")) {
            pushOptions.setNotificationChannelId(channelId);
        }

        String channelName = args.optString(PUSH_NOTIFICATION_CHANNEL_NAME);
        if (!channelName.trim().equals("")) {
            pushOptions.setNotificationChannelName(channelName);
        }

        EMMA.getInstance().startPushSystem(pushOptions.build());

        pushInitialized = true;

        callbackContext.success();
        return true;
    }

    private boolean trackEvent(JSONObject args, final CallbackContext callbackContext) {

        String token = args.optString(EVENT_TOKEN);
        JSONObject attributes = args.optJSONObject(EVENT_ATTRIBUTES);

        if (token.trim().equals("")) {
            String msg = SESSION_KEY + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        EMMAEventRequest request = new EMMAEventRequest(token);

        if (attributes != null) {
            try {
                Map<String, String> keyValueAttr = objectToMap(attributes);
                request.setAttributes(Collections.unmodifiableMap(keyValueAttr));
            } catch (JSONException ex) {
                EMMALog.e(KEY_VALUE_MAPPING_ERROR);
            } catch (IllegalArgumentException ex) {
                EMMALog.e(ex.getMessage());
            }
        }

        EMMA.getInstance().trackEvent(request);
        callbackContext.success();
        return true;
    }

    private boolean trackUserExtras(JSONObject object, CallbackContext callbackContext) {
        try {
            Map<String, String> userTags = objectToMap(object);
            EMMA.getInstance().trackExtraUserInfo(userTags);
            callbackContext.success();
            return true;
        } catch (JSONException ex) {
            String msg = KEY_VALUE_MAPPING_ERROR;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        } catch (IllegalArgumentException ex) {
            EMMALog.e(ex.getMessage());
            callbackContext.error(ex.getMessage());
            return false;
        }
    }

    private boolean loginUser(JSONObject args, CallbackContext callbackContext) {
        return loginRegisterUser(args, ActionTypes.LOGIN, callbackContext);
    }

    private boolean registerUser(JSONObject args, CallbackContext callbackContext) {
        return loginRegisterUser(args, ActionTypes.REGISTER, callbackContext);
    }

    private boolean loginRegisterUser(JSONObject args, ActionTypes type, CallbackContext callbackContext) {
        String userId = args.optString(USER_ID);
        String email = args.optString(EMAIL);
        JSONObject extras = args.optJSONObject(EXTRAS);

        if (userId == null) {
            String msg = USER_ID + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        if (extras != null) {
            try {
                Map<String, String> extrasMap = objectToMap(extras);
                if (type == ActionTypes.LOGIN) {
                    EMMA.getInstance().loginUser(userId, email, extrasMap);
                } else {
                    EMMA.getInstance().registerUser(userId, email, extrasMap);
                }
                callbackContext.success();
                return true;
            } catch (JSONException e) {
                EMMALog.e(KEY_VALUE_MAPPING_ERROR);
            } catch (IllegalArgumentException ex) {
                EMMALog.e(ex.getMessage());
            }
        }

        if (type == ActionTypes.LOGIN) {
            EMMA.getInstance().loginUser(userId, email);
        } else {
            EMMA.getInstance().registerUser(userId, email);
        }

        callbackContext.success();
        return true;
    }

    private boolean startOrder(JSONObject args, CallbackContext callbackContext) {
        String orderId = args.optString(ORDER_ID);
        if (orderId.trim().equals("")) {
            String msg = ORDER_ID + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        float totalPrice;
        try {
            totalPrice = (float) args.getDouble(ORDER_TOTAL_PRICE);
        } catch (JSONException e) {
            String msg = ORDER_TOTAL_PRICE + MANDATORY_NOT_ZERO;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        String customerId;
        try {
            customerId = args.getString(ORDER_CUSTOMER_ID);
        } catch (JSONException e) {
            customerId = null;
        }

        String currencyCode;
        try {
            currencyCode = args.getString(ORDER_CURRENCY_CODE);
        } catch (JSONException e) {
            currencyCode = null;
        }

        String coupon;
        try {
            coupon = args.getString(ORDER_COUPON);
        } catch (JSONException e) {
            coupon = null;
        }

        JSONObject extras = args.optJSONObject(EXTRAS);
        Map<String, String> extrasMap = null;
        if (extras != null) {
            try {
                extrasMap = objectToMap(extras);
            } catch (JSONException e) {
                EMMALog.e(KEY_VALUE_MAPPING_ERROR);
            } catch (IllegalArgumentException ex) {
                EMMALog.e(ex.getMessage());
            }
        }

        EMMA.getInstance().startOrder(orderId,
                customerId, totalPrice, currencyCode, coupon, extrasMap);
        callbackContext.success();
        return true;
    }

    private boolean addProduct(JSONObject args, CallbackContext callbackContext) {
        String productId = args.optString(ORDER_PRODUCT_ID);
        if (productId.trim().equals("")) {
            String msg = ORDER_PRODUCT_ID + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        String productName = args.optString(ORDER_PRODUCT_NAME);
        if (productName.trim().equals("")) {
            String msg = ORDER_PRODUCT_NAME + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        int quantity = args.optInt(ORDER_PRODUCT_QUANTITY, 0);
        if (quantity == 0) {
            String msg = ORDER_PRODUCT_QUANTITY + MANDATORY_NOT_ZERO;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        double price = args.optDouble(ORDER_PRODUCT_PRICE, 0);
        if (price == 0) {
            String msg = ORDER_PRODUCT_PRICE + MANDATORY_NOT_ZERO;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }


        JSONObject extras = args.optJSONObject(EXTRAS);
        Map<String, String> extrasMap = null;
        if (extras != null) {
            try {
                extrasMap = objectToMap(extras);
            } catch (JSONException e) {
                EMMALog.e(KEY_VALUE_MAPPING_ERROR);
            } catch (IllegalArgumentException ex) {
                EMMALog.e(ex.getMessage());
            }
        }

        EMMA.getInstance().addProduct(productId, productName, quantity, (float) price, extrasMap);
        callbackContext.success();
        return true;
    }

    private boolean trackOrder(CallbackContext callbackContext) {
        EMMA.getInstance().trackOrder();
        callbackContext.success();
        return true;
    }

    private boolean cancelOrder(JSONArray array, CallbackContext callbackContext) {
        String orderId = array.optString(0);
        if (orderId.trim().equals("")) {
            String msg = ORDER_ID + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        EMMA.getInstance().cancelOrder(orderId);
        callbackContext.success();
        return true;
    }

    private boolean checkForRichPush(CallbackContext callbackContext) {
        EMMA.getInstance().checkForRichPushUrl();
        callbackContext.success();
        return true;
    }


    private boolean inAppMessage(JSONObject args, CallbackContext callbackContext) {

        String inAppType = args.optString(INAPP_TYPE);
        if (inAppType.trim().equals("")) {
            String msg = INAPP_TYPE + MANDATORY_NOT_EMPTY;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        EMMACampaign.Type type = inAppTypeFromString(inAppType);

        if (type == null) {
            String msg = INAPP_TYPE + INAPP_TYPE_INVALID;
            EMMALog.e(msg);
            callbackContext.error(msg);
            return false;
        }

        if (type == EMMACampaign.Type.NATIVEAD) {
            String templateId = args.optString(INAPP_TEMPLATE_ID);
            if (templateId.trim().equals("")) {
                String msg = "For nativeAd " + INAPP_TEMPLATE_ID + MANDATORY_NOT_EMPTY;
                EMMALog.e(msg);
                callbackContext.error(msg);
                return false;
            }

            processNativeAd(templateId, args.optBoolean(INAPP_BATCH), callbackContext);
        } else {
            EMMA.getInstance().setCurrentActivity(cordova.getActivity());

            EMMAInAppRequest request = new EMMAInAppRequest(type);
            EMMA.getInstance().getInAppMessage(request);

            callbackContext.success();
        }

        return true;
    }

    private void processNativeAd(String templateId, boolean batch, CallbackContext callbackContext) {
        if (batch) {
            processBatchNativeAd(templateId, callbackContext);
        } else {
            processSimpleNativeAd(templateId, callbackContext);
        }
    }

    private void processSimpleNativeAd(String templateId, final CallbackContext callbackContext) {
        EMMANativeAdRequest request = new EMMANativeAdRequest();
        request.setTemplateId(templateId);

        EMMA.getInstance().getInAppMessage(request, new EMMANativeAdInterface() {
            @Override
            public void onReceived(EMMANativeAd nativeAd) {
                processNativeAdResponse(Collections.singletonList(nativeAd), callbackContext);
            }

            @Override
            public void onShown(EMMACampaign emmaCampaign) {

            }

            @Override
            public void onHide(EMMACampaign emmaCampaign) {

            }

            @Override
            public void onClose(EMMACampaign emmaCampaign) {

            }
        });
    }

    private void processBatchNativeAd(String templateId, final CallbackContext callbackContext) {
        EMMANativeAdRequest request = new EMMANativeAdRequest();
        request.setTemplateId(templateId);
        request.setBatch(true);

        EMMA.getInstance().getInAppMessage(request, new EMMABatchNativeAdInterface() {
            @Override
            public void onBatchReceived(List<EMMANativeAd> list) {
                processNativeAdResponse(list, callbackContext);
            }

            @Override
            public void onShown(EMMACampaign emmaCampaign) {

            }

            @Override
            public void onHide(EMMACampaign emmaCampaign) {

            }

            @Override
            public void onClose(EMMACampaign emmaCampaign) {

            }
        });
    }

    private void processNativeAdResponse(List<EMMANativeAd> list,
                                         CallbackContext callbackContext) {
        JSONArray result = nativeAdsToJSON(list);

        PluginResult pluginResult =
                new PluginResult(PluginResult.Status.OK, result);

        pluginResult.setKeepCallback(true);

        callbackContext.sendPluginResult(pluginResult);
    }

    private EMMACampaign.Type inAppTypeFromString(String type) {
        return inAppTypesMap.get(type);
    }

    private Map<String, String> objectToMap(JSONObject object)
            throws JSONException, IllegalArgumentException {
        Map<String, String> result = new HashMap<>();
        Iterator<String> keysItr = object.keys();
        while (keysItr.hasNext()) {
            String key = keysItr.next();
            Object value = object.get(key);

            if ((value instanceof JSONObject) || (value instanceof JSONArray)) {
                throw new IllegalArgumentException(MAPPING_VALUE_ERROR);
            }

            result.put(key, String.valueOf(value));
        }

        return result;
    }

    private List<String> arrayToStringList(String errorName, JSONArray array) {
        List<String> result = new ArrayList<>();
        for (int i = 0; i < array.length(); i++) {
            String candidate = array.optString(i);
            if (candidate.trim().equals("")) {
                EMMALog.w("Processing " + errorName + "at position "
                        + i + " parameter not valid must be string type");
                continue;
            }

            result.add(candidate);
        }

        return result;
    }

    private boolean sessionKeyInMetadata(Context applicationContext) {
        Bundle metaData = ManifestInfo.getApplicationMetadata(applicationContext);
        return metaData != null && metaData.getString("io.emma.SESSION_KEY") != null;
    }

    private @DrawableRes
    int getNotificationIcon(Context context, String imageName) {
        Resources res = context.getResources();
        return res.getIdentifier(imageName, "drawable", context.getPackageName());
    }

    private @ColorInt
    int getNotificationColor(String hexColor) {
        return Color.parseColor(hexColor);
    }

    private void initInAppTypes() {
        inAppTypesMap = new HashMap<>();
        inAppTypesMap.put(INAPP_STARTVIEW, EMMACampaign.Type.STARTVIEW);
        inAppTypesMap.put(INAPP_ADBALL, EMMACampaign.Type.ADBALL);
        inAppTypesMap.put(INAPP_BANNER, EMMACampaign.Type.BANNER);
        inAppTypesMap.put(INAPP_STRIP, EMMACampaign.Type.STRIP);
        inAppTypesMap.put(INAPP_NATIVEAD, EMMACampaign.Type.NATIVEAD);
    }

    private JSONArray nativeAdsToJSON(List<EMMANativeAd> nativeAds) {
        JSONArray array = new JSONArray();

        for (EMMANativeAd nativeAd : nativeAds) {
            JSONObject object = nativeAdToJSON(nativeAd);
            if (object != null) {
                array.put(object);
            }
        }

        return array;
    }

    private JSONObject nativeAdToJSON(EMMANativeAd nativeAd) {
        JSONObject object = new JSONObject();

        try {
            object.put("id", nativeAd.getCampaignID().intValue());
            object.put("templateId", nativeAd.getTemplateId());
            object.put("times", nativeAd.getTimes().intValue());
            object.put("tag", nativeAd.getTag());
            object.put("showOn", nativeAd.showOnWebView() ? "inapp" : "browser");
            object.put("fields", processNativeAdFields(nativeAd.getNativeAdContent()));
        } catch (JSONException e) {
            EMMALog.e("Error parsing native ad", e);
            return null;
        }

        return object;
    }


    private JSONArray processNativeAdFields(Map<String, EMMANativeAdField> fields) throws JSONException {
        JSONArray result = new JSONArray();

        for (Map.Entry<String, EMMANativeAdField> entry : fields.entrySet()) {
            JSONObject object = new JSONObject();
            object.put("name", entry.getValue().getFieldName());
            object.put("type", entry.getValue().getFieldType());
            object.put("subtype", entry.getValue().getFieldSubType());
            object.put("value", entry.getValue().getFieldValue());

            result.put(object);
        }

        return result;
    }
}