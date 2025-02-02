#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.6 (swiftlang-5.6.0.323.62 clang-1316.0.20.8)
#ifndef EMMA_IOS_SWIFT_H
#define EMMA_IOS_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import ObjectiveC;
#endif

#import <EMMA_iOS/EMMA_iOS.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="EMMA_iOS",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class EMMAClickMode;
@class NSObject;

SWIFT_CLASS("_TtC8EMMA_iOS18EMMAAdBallCampaign")
@interface EMMAAdBallCampaign : EMMACampaign
@property (nonatomic, strong) EMMAClickMode * _Nonnull clickMode;
@property (nonatomic) NSInteger horizontalLocation;
@property (nonatomic) NSInteger verticalLocation;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)parseResponseInfo:(NSDictionary * _Nonnull)response;
- (null_unspecified instancetype)initWithType:(EMMACampaignType)type SWIFT_UNAVAILABLE;
@end

enum EMMAClickModeType : NSInteger;
@class NSURL;

SWIFT_CLASS("_TtC8EMMA_iOS13EMMAClickMode")
@interface EMMAClickMode : NSObject
@property (nonatomic) enum EMMAClickModeType type;
@property (nonatomic, copy) NSURL * _Nullable ctaUrl;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init:(NSDictionary * _Nonnull)rawClickMode OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, EMMAClickModeType, open) {
  EMMAClickModeTypeTap = 0,
  EMMAClickModeTypeDeeplink = 1,
  EMMAClickModeTypeChangeUrl = 2,
  EMMAClickModeTypeCustomUrl = 3,
};

@class NSString;
@protocol EMMAInAppPluginProtocol;

SWIFT_CLASS("_TtC8EMMA_iOS25EMMAInAppPluginController")
@interface EMMAInAppPluginController : NSObject
@property (nonatomic, readonly, copy) NSDictionary<NSString *, id <EMMAInAppPluginProtocol>> * _Nonnull plugins;
- (void)addPlugins:(NSArray<id <EMMAInAppPluginProtocol>> * _Nonnull)addedPlugins;
- (BOOL)isAvailablePlugin:(NSString * _Nonnull)type SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8EMMA_iOS19EMMAInAppPluginImpl")
@interface EMMAInAppPluginImpl : NSObject
+ (void)sendImpressionWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)sendClickWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)invokeShownDelegatesWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)invokeHideDelegatesWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)invokeCloseDelegatesWithCampaign:(EMMACampaign * _Nonnull)campaign;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class EMMANativeAd;

SWIFT_PROTOCOL("_TtP8EMMA_iOS23EMMAInAppPluginProtocol_")
@protocol EMMAInAppPluginProtocol
- (NSString * _Nonnull)getId SWIFT_WARN_UNUSED_RESULT;
- (void)show:(EMMANativeAd * _Nonnull)nativeAd;
- (void)dismiss;
@end


SWIFT_CLASS("_TtC8EMMA_iOS17EMMANativeAdField")
@interface EMMANativeAdField : NSObject
@property (nonatomic, copy) NSString * _Nonnull name;
@property (nonatomic, copy) NSString * _Nonnull type;
@property (nonatomic, copy) NSString * _Nonnull subType;
@property (nonatomic, copy) NSString * _Nonnull value;
@property (nonatomic, copy) NSArray<NSDictionary<NSString *, id> *> * _Nullable containerValue;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)fromDict:(NSDictionary<NSString *, id> * _Nonnull)dict;
@end

@class UNNotificationRequest;
@class UNMutableNotificationContent;
@class UNNotificationContent;

SWIFT_CLASS("_TtC8EMMA_iOS33EMMANotificationServiceController") SWIFT_AVAILABILITY(ios,introduced=10.0)
@interface EMMANotificationServiceController : NSObject
+ (void)didReceiveNotificationRequestWithRequest:(UNNotificationRequest * _Nonnull)request withNotificationContent:(UNMutableNotificationContent * _Nonnull)content AndCompletionHandler:(void (^ _Nonnull)(UNNotificationContent * _Nullable))completion;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class EMMAPushActionButton;
@class EMMAPushPayload;

SWIFT_CLASS("_TtC8EMMA_iOS8EMMAPush")
@interface EMMAPush : EMMACampaign
@property (nonatomic, copy) NSString * _Nullable message;
@property (nonatomic, copy) NSString * _Nullable tag;
@property (nonatomic) BOOL showAlert;
@property (nonatomic, strong) EMMAPushActionButton * _Nullable openedFromAction;
- (nonnull instancetype)initWithPayload:(EMMAPushPayload * _Nonnull)payload OBJC_DESIGNATED_INITIALIZER;
- (null_unspecified instancetype)initWithType:(EMMACampaignType)type SWIFT_UNAVAILABLE;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

enum EMMAPushButtonIconType : NSInteger;

SWIFT_CLASS("_TtC8EMMA_iOS20EMMAPushActionButton")
@interface EMMAPushActionButton : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
@property (nonatomic, readonly, copy) NSString * _Nonnull text;
@property (nonatomic, copy) NSURL * _Nullable action;
@property (nonatomic) enum EMMAPushButtonIconType isSystemIcon;
@property (nonatomic, copy) NSString * _Nullable icon;
- (nullable instancetype)init:(NSDictionary * _Nonnull)rawButton OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC8EMMA_iOS23EMMAPushBadgeController")
@interface EMMAPushBadgeController : NSObject
+ (void)clearBadgeFromOpen:(BOOL)fromOpen;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, EMMAPushButtonIconType, open) {
  EMMAPushButtonIconTypeSystem = 0,
  EMMAPushButtonIconTypeCustom = 1,
};


SWIFT_CLASS("_TtC8EMMA_iOS15EMMAPushOptions")
@interface EMMAPushOptions : NSObject
@property (nonatomic) BOOL showOpenAlert;
@property (nonatomic) BOOL badgeClearing;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8EMMA_iOS15EMMAPushPayload")
@interface EMMAPushPayload : NSObject
- (nullable instancetype)initWithUserInfo:(NSDictionary * _Nullable)userInfo OBJC_DESIGNATED_INITIALIZER;
- (EMMAPushActionButton * _Nullable)getActionButtonByActionId:(NSString * _Nonnull)actionId SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC8EMMA_iOS21EMMAStartViewCampaign")
@interface EMMAStartViewCampaign : EMMACampaign
@property (nonatomic, strong) EMMAClickMode * _Nonnull clickMode;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)parseResponseInfo:(NSDictionary * _Nonnull)response;
- (null_unspecified instancetype)initWithType:(EMMACampaignType)type SWIFT_UNAVAILABLE;
@end

@class UIColor;
@class NSTimeZone;
@class NSDate;
@class UIApplication;

SWIFT_CLASS("_TtC8EMMA_iOS9EMMAUtils")
@interface EMMAUtils : NSObject
+ (UIColor * _Nonnull)hexaStrToColor:(NSString * _Nonnull)hexa SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)newDateWithDefaultTimezone SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)newDateWithTimezone:(NSTimeZone * _Nullable)timezone SWIFT_WARN_UNUSED_RESULT;
+ (NSDate * _Nullable)dateFromStringDefaultFormat:(NSString * _Nonnull)dateString SWIFT_WARN_UNUSED_RESULT;
+ (NSDate * _Nullable)dateFromString:(NSString * _Nonnull)dateString withFormat:(NSString * _Nonnull)format SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)dateToString:(NSDate * _Nonnull)date withFormat:(NSString * _Nonnull)format andTimeZone:(NSTimeZone * _Nullable)timeZone SWIFT_WARN_UNUSED_RESULT;
+ (NSDate * _Nonnull)addHoursWithHours:(NSInteger)hours toDate:(NSDate * _Nonnull)date SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isWebAddress:(NSURL * _Nullable)url SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)areEqualsUrls:(NSURL * _Nullable)url1 :(NSURL * _Nullable)url2 SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)dateToStringLocalTimeWithDate:(NSDate * _Nonnull)date withFormat:(NSString * _Nonnull)format SWIFT_WARN_UNUSED_RESULT;
+ (UIApplication * _Nullable)getSharedApplication SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isNil:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isEmpty:(NSString * _Nullable)value SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)valueToBool:(id _Nullable)value SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nullable)getAppBundleIdentifier SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nullable)getAppGroupName SWIFT_WARN_UNUSED_RESULT;
+ (NSDictionary<NSString *, NSString *> * _Nonnull)getUrlParams:(NSURL * _Nonnull)url SWIFT_WARN_UNUSED_RESULT;
+ (void)sleepWithSeconds:(double)seconds;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIWindow;
@class UIViewController;

SWIFT_CLASS("_TtC8EMMA_iOS13EMMAViewUtils")
@interface EMMAViewUtils : NSObject
+ (UIWindow * _Nullable)getKeyWindow SWIFT_WARN_UNUSED_RESULT;
+ (CGFloat)safeAreaMargins SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)hasTopNotch SWIFT_WARN_UNUSED_RESULT;
+ (UIViewController * _Nullable)getRootViewController SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isSwiftUIApp:(NSString * _Nonnull)viewControllerName SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__ARM_ARCH_7A__) && __ARM_ARCH_7A__
// Generated by Apple Swift version 5.6 (swiftlang-5.6.0.323.62 clang-1316.0.20.8)
#ifndef EMMA_IOS_SWIFT_H
#define EMMA_IOS_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import ObjectiveC;
#endif

#import <EMMA_iOS/EMMA_iOS.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="EMMA_iOS",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class EMMAClickMode;
@class NSObject;

SWIFT_CLASS("_TtC8EMMA_iOS18EMMAAdBallCampaign")
@interface EMMAAdBallCampaign : EMMACampaign
@property (nonatomic, strong) EMMAClickMode * _Nonnull clickMode;
@property (nonatomic) NSInteger horizontalLocation;
@property (nonatomic) NSInteger verticalLocation;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)parseResponseInfo:(NSDictionary * _Nonnull)response;
- (null_unspecified instancetype)initWithType:(EMMACampaignType)type SWIFT_UNAVAILABLE;
@end

enum EMMAClickModeType : NSInteger;
@class NSURL;

SWIFT_CLASS("_TtC8EMMA_iOS13EMMAClickMode")
@interface EMMAClickMode : NSObject
@property (nonatomic) enum EMMAClickModeType type;
@property (nonatomic, copy) NSURL * _Nullable ctaUrl;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init:(NSDictionary * _Nonnull)rawClickMode OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, EMMAClickModeType, open) {
  EMMAClickModeTypeTap = 0,
  EMMAClickModeTypeDeeplink = 1,
  EMMAClickModeTypeChangeUrl = 2,
  EMMAClickModeTypeCustomUrl = 3,
};

@class NSString;
@protocol EMMAInAppPluginProtocol;

SWIFT_CLASS("_TtC8EMMA_iOS25EMMAInAppPluginController")
@interface EMMAInAppPluginController : NSObject
@property (nonatomic, readonly, copy) NSDictionary<NSString *, id <EMMAInAppPluginProtocol>> * _Nonnull plugins;
- (void)addPlugins:(NSArray<id <EMMAInAppPluginProtocol>> * _Nonnull)addedPlugins;
- (BOOL)isAvailablePlugin:(NSString * _Nonnull)type SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8EMMA_iOS19EMMAInAppPluginImpl")
@interface EMMAInAppPluginImpl : NSObject
+ (void)sendImpressionWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)sendClickWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)invokeShownDelegatesWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)invokeHideDelegatesWithCampaign:(EMMACampaign * _Nonnull)campaign;
+ (void)invokeCloseDelegatesWithCampaign:(EMMACampaign * _Nonnull)campaign;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class EMMANativeAd;

SWIFT_PROTOCOL("_TtP8EMMA_iOS23EMMAInAppPluginProtocol_")
@protocol EMMAInAppPluginProtocol
- (NSString * _Nonnull)getId SWIFT_WARN_UNUSED_RESULT;
- (void)show:(EMMANativeAd * _Nonnull)nativeAd;
- (void)dismiss;
@end


SWIFT_CLASS("_TtC8EMMA_iOS17EMMANativeAdField")
@interface EMMANativeAdField : NSObject
@property (nonatomic, copy) NSString * _Nonnull name;
@property (nonatomic, copy) NSString * _Nonnull type;
@property (nonatomic, copy) NSString * _Nonnull subType;
@property (nonatomic, copy) NSString * _Nonnull value;
@property (nonatomic, copy) NSArray<NSDictionary<NSString *, id> *> * _Nullable containerValue;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)fromDict:(NSDictionary<NSString *, id> * _Nonnull)dict;
@end

@class UNNotificationRequest;
@class UNMutableNotificationContent;
@class UNNotificationContent;

SWIFT_CLASS("_TtC8EMMA_iOS33EMMANotificationServiceController") SWIFT_AVAILABILITY(ios,introduced=10.0)
@interface EMMANotificationServiceController : NSObject
+ (void)didReceiveNotificationRequestWithRequest:(UNNotificationRequest * _Nonnull)request withNotificationContent:(UNMutableNotificationContent * _Nonnull)content AndCompletionHandler:(void (^ _Nonnull)(UNNotificationContent * _Nullable))completion;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class EMMAPushActionButton;
@class EMMAPushPayload;

SWIFT_CLASS("_TtC8EMMA_iOS8EMMAPush")
@interface EMMAPush : EMMACampaign
@property (nonatomic, copy) NSString * _Nullable message;
@property (nonatomic, copy) NSString * _Nullable tag;
@property (nonatomic) BOOL showAlert;
@property (nonatomic, strong) EMMAPushActionButton * _Nullable openedFromAction;
- (nonnull instancetype)initWithPayload:(EMMAPushPayload * _Nonnull)payload OBJC_DESIGNATED_INITIALIZER;
- (null_unspecified instancetype)initWithType:(EMMACampaignType)type SWIFT_UNAVAILABLE;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

enum EMMAPushButtonIconType : NSInteger;

SWIFT_CLASS("_TtC8EMMA_iOS20EMMAPushActionButton")
@interface EMMAPushActionButton : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull id;
@property (nonatomic, readonly, copy) NSString * _Nonnull text;
@property (nonatomic, copy) NSURL * _Nullable action;
@property (nonatomic) enum EMMAPushButtonIconType isSystemIcon;
@property (nonatomic, copy) NSString * _Nullable icon;
- (nullable instancetype)init:(NSDictionary * _Nonnull)rawButton OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC8EMMA_iOS23EMMAPushBadgeController")
@interface EMMAPushBadgeController : NSObject
+ (void)clearBadgeFromOpen:(BOOL)fromOpen;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, EMMAPushButtonIconType, open) {
  EMMAPushButtonIconTypeSystem = 0,
  EMMAPushButtonIconTypeCustom = 1,
};


SWIFT_CLASS("_TtC8EMMA_iOS15EMMAPushOptions")
@interface EMMAPushOptions : NSObject
@property (nonatomic) BOOL showOpenAlert;
@property (nonatomic) BOOL badgeClearing;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8EMMA_iOS15EMMAPushPayload")
@interface EMMAPushPayload : NSObject
- (nullable instancetype)initWithUserInfo:(NSDictionary * _Nullable)userInfo OBJC_DESIGNATED_INITIALIZER;
- (EMMAPushActionButton * _Nullable)getActionButtonByActionId:(NSString * _Nonnull)actionId SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC8EMMA_iOS21EMMAStartViewCampaign")
@interface EMMAStartViewCampaign : EMMACampaign
@property (nonatomic, strong) EMMAClickMode * _Nonnull clickMode;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)parseResponseInfo:(NSDictionary * _Nonnull)response;
- (null_unspecified instancetype)initWithType:(EMMACampaignType)type SWIFT_UNAVAILABLE;
@end

@class UIColor;
@class NSTimeZone;
@class NSDate;
@class UIApplication;

SWIFT_CLASS("_TtC8EMMA_iOS9EMMAUtils")
@interface EMMAUtils : NSObject
+ (UIColor * _Nonnull)hexaStrToColor:(NSString * _Nonnull)hexa SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)newDateWithDefaultTimezone SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)newDateWithTimezone:(NSTimeZone * _Nullable)timezone SWIFT_WARN_UNUSED_RESULT;
+ (NSDate * _Nullable)dateFromStringDefaultFormat:(NSString * _Nonnull)dateString SWIFT_WARN_UNUSED_RESULT;
+ (NSDate * _Nullable)dateFromString:(NSString * _Nonnull)dateString withFormat:(NSString * _Nonnull)format SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)dateToString:(NSDate * _Nonnull)date withFormat:(NSString * _Nonnull)format andTimeZone:(NSTimeZone * _Nullable)timeZone SWIFT_WARN_UNUSED_RESULT;
+ (NSDate * _Nonnull)addHoursWithHours:(NSInteger)hours toDate:(NSDate * _Nonnull)date SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isWebAddress:(NSURL * _Nullable)url SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)areEqualsUrls:(NSURL * _Nullable)url1 :(NSURL * _Nullable)url2 SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nonnull)dateToStringLocalTimeWithDate:(NSDate * _Nonnull)date withFormat:(NSString * _Nonnull)format SWIFT_WARN_UNUSED_RESULT;
+ (UIApplication * _Nullable)getSharedApplication SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isNil:(id _Nullable)object SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isEmpty:(NSString * _Nullable)value SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)valueToBool:(id _Nullable)value SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nullable)getAppBundleIdentifier SWIFT_WARN_UNUSED_RESULT;
+ (NSString * _Nullable)getAppGroupName SWIFT_WARN_UNUSED_RESULT;
+ (NSDictionary<NSString *, NSString *> * _Nonnull)getUrlParams:(NSURL * _Nonnull)url SWIFT_WARN_UNUSED_RESULT;
+ (void)sleepWithSeconds:(double)seconds;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIWindow;
@class UIViewController;

SWIFT_CLASS("_TtC8EMMA_iOS13EMMAViewUtils")
@interface EMMAViewUtils : NSObject
+ (UIWindow * _Nullable)getKeyWindow SWIFT_WARN_UNUSED_RESULT;
+ (CGFloat)safeAreaMargins SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)hasTopNotch SWIFT_WARN_UNUSED_RESULT;
+ (UIViewController * _Nullable)getRootViewController SWIFT_WARN_UNUSED_RESULT;
+ (BOOL)isSwiftUIApp:(NSString * _Nonnull)viewControllerName SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#endif
