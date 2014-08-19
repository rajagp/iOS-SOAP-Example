#import <Foundation/Foundation.h>
#import "USAdditions.h"
#import <libxml/tree.h>
#import "USGlobals.h"
@class CurrencyConvertorSvc_ConversionRate;
@class CurrencyConvertorSvc_ConversionRateResponse;
typedef enum {
	CurrencyConvertorSvc_Currency_none = 0,
	CurrencyConvertorSvc_Currency_AFA,
	CurrencyConvertorSvc_Currency_ALL,
	CurrencyConvertorSvc_Currency_DZD,
	CurrencyConvertorSvc_Currency_ARS,
	CurrencyConvertorSvc_Currency_AWG,
	CurrencyConvertorSvc_Currency_AUD,
	CurrencyConvertorSvc_Currency_BSD,
	CurrencyConvertorSvc_Currency_BHD,
	CurrencyConvertorSvc_Currency_BDT,
	CurrencyConvertorSvc_Currency_BBD,
	CurrencyConvertorSvc_Currency_BZD,
	CurrencyConvertorSvc_Currency_BMD,
	CurrencyConvertorSvc_Currency_BTN,
	CurrencyConvertorSvc_Currency_BOB,
	CurrencyConvertorSvc_Currency_BWP,
	CurrencyConvertorSvc_Currency_BRL,
	CurrencyConvertorSvc_Currency_GBP,
	CurrencyConvertorSvc_Currency_BND,
	CurrencyConvertorSvc_Currency_BIF,
	CurrencyConvertorSvc_Currency_XOF,
	CurrencyConvertorSvc_Currency_XAF,
	CurrencyConvertorSvc_Currency_KHR,
	CurrencyConvertorSvc_Currency_CAD,
	CurrencyConvertorSvc_Currency_CVE,
	CurrencyConvertorSvc_Currency_KYD,
	CurrencyConvertorSvc_Currency_CLP,
	CurrencyConvertorSvc_Currency_CNY,
	CurrencyConvertorSvc_Currency_COP,
	CurrencyConvertorSvc_Currency_KMF,
	CurrencyConvertorSvc_Currency_CRC,
	CurrencyConvertorSvc_Currency_HRK,
	CurrencyConvertorSvc_Currency_CUP,
	CurrencyConvertorSvc_Currency_CYP,
	CurrencyConvertorSvc_Currency_CZK,
	CurrencyConvertorSvc_Currency_DKK,
	CurrencyConvertorSvc_Currency_DJF,
	CurrencyConvertorSvc_Currency_DOP,
	CurrencyConvertorSvc_Currency_XCD,
	CurrencyConvertorSvc_Currency_EGP,
	CurrencyConvertorSvc_Currency_SVC,
	CurrencyConvertorSvc_Currency_EEK,
	CurrencyConvertorSvc_Currency_ETB,
	CurrencyConvertorSvc_Currency_EUR,
	CurrencyConvertorSvc_Currency_FKP,
	CurrencyConvertorSvc_Currency_GMD,
	CurrencyConvertorSvc_Currency_GHC,
	CurrencyConvertorSvc_Currency_GIP,
	CurrencyConvertorSvc_Currency_XAU,
	CurrencyConvertorSvc_Currency_GTQ,
	CurrencyConvertorSvc_Currency_GNF,
	CurrencyConvertorSvc_Currency_GYD,
	CurrencyConvertorSvc_Currency_HTG,
	CurrencyConvertorSvc_Currency_HNL,
	CurrencyConvertorSvc_Currency_HKD,
	CurrencyConvertorSvc_Currency_HUF,
	CurrencyConvertorSvc_Currency_ISK,
	CurrencyConvertorSvc_Currency_INR,
	CurrencyConvertorSvc_Currency_IDR,
	CurrencyConvertorSvc_Currency_IQD,
	CurrencyConvertorSvc_Currency_ILS,
	CurrencyConvertorSvc_Currency_JMD,
	CurrencyConvertorSvc_Currency_JPY,
	CurrencyConvertorSvc_Currency_JOD,
	CurrencyConvertorSvc_Currency_KZT,
	CurrencyConvertorSvc_Currency_KES,
	CurrencyConvertorSvc_Currency_KRW,
	CurrencyConvertorSvc_Currency_KWD,
	CurrencyConvertorSvc_Currency_LAK,
	CurrencyConvertorSvc_Currency_LVL,
	CurrencyConvertorSvc_Currency_LBP,
	CurrencyConvertorSvc_Currency_LSL,
	CurrencyConvertorSvc_Currency_LRD,
	CurrencyConvertorSvc_Currency_LYD,
	CurrencyConvertorSvc_Currency_LTL,
	CurrencyConvertorSvc_Currency_MOP,
	CurrencyConvertorSvc_Currency_MKD,
	CurrencyConvertorSvc_Currency_MGF,
	CurrencyConvertorSvc_Currency_MWK,
	CurrencyConvertorSvc_Currency_MYR,
	CurrencyConvertorSvc_Currency_MVR,
	CurrencyConvertorSvc_Currency_MTL,
	CurrencyConvertorSvc_Currency_MRO,
	CurrencyConvertorSvc_Currency_MUR,
	CurrencyConvertorSvc_Currency_MXN,
	CurrencyConvertorSvc_Currency_MDL,
	CurrencyConvertorSvc_Currency_MNT,
	CurrencyConvertorSvc_Currency_MAD,
	CurrencyConvertorSvc_Currency_MZM,
	CurrencyConvertorSvc_Currency_MMK,
	CurrencyConvertorSvc_Currency_NAD,
	CurrencyConvertorSvc_Currency_NPR,
	CurrencyConvertorSvc_Currency_ANG,
	CurrencyConvertorSvc_Currency_NZD,
	CurrencyConvertorSvc_Currency_NIO,
	CurrencyConvertorSvc_Currency_NGN,
	CurrencyConvertorSvc_Currency_KPW,
	CurrencyConvertorSvc_Currency_NOK,
	CurrencyConvertorSvc_Currency_OMR,
	CurrencyConvertorSvc_Currency_XPF,
	CurrencyConvertorSvc_Currency_PKR,
	CurrencyConvertorSvc_Currency_XPD,
	CurrencyConvertorSvc_Currency_PAB,
	CurrencyConvertorSvc_Currency_PGK,
	CurrencyConvertorSvc_Currency_PYG,
	CurrencyConvertorSvc_Currency_PEN,
	CurrencyConvertorSvc_Currency_PHP,
	CurrencyConvertorSvc_Currency_XPT,
	CurrencyConvertorSvc_Currency_PLN,
	CurrencyConvertorSvc_Currency_QAR,
	CurrencyConvertorSvc_Currency_ROL,
	CurrencyConvertorSvc_Currency_RUB,
	CurrencyConvertorSvc_Currency_WST,
	CurrencyConvertorSvc_Currency_STD,
	CurrencyConvertorSvc_Currency_SAR,
	CurrencyConvertorSvc_Currency_SCR,
	CurrencyConvertorSvc_Currency_SLL,
	CurrencyConvertorSvc_Currency_XAG,
	CurrencyConvertorSvc_Currency_SGD,
	CurrencyConvertorSvc_Currency_SKK,
	CurrencyConvertorSvc_Currency_SIT,
	CurrencyConvertorSvc_Currency_SBD,
	CurrencyConvertorSvc_Currency_SOS,
	CurrencyConvertorSvc_Currency_ZAR,
	CurrencyConvertorSvc_Currency_LKR,
	CurrencyConvertorSvc_Currency_SHP,
	CurrencyConvertorSvc_Currency_SDD,
	CurrencyConvertorSvc_Currency_SRG,
	CurrencyConvertorSvc_Currency_SZL,
	CurrencyConvertorSvc_Currency_SEK,
	CurrencyConvertorSvc_Currency_CHF,
	CurrencyConvertorSvc_Currency_SYP,
	CurrencyConvertorSvc_Currency_TWD,
	CurrencyConvertorSvc_Currency_TZS,
	CurrencyConvertorSvc_Currency_THB,
	CurrencyConvertorSvc_Currency_TOP,
	CurrencyConvertorSvc_Currency_TTD,
	CurrencyConvertorSvc_Currency_TND,
	CurrencyConvertorSvc_Currency_TRL,
	CurrencyConvertorSvc_Currency_USD,
	CurrencyConvertorSvc_Currency_AED,
	CurrencyConvertorSvc_Currency_UGX,
	CurrencyConvertorSvc_Currency_UAH,
	CurrencyConvertorSvc_Currency_UYU,
	CurrencyConvertorSvc_Currency_VUV,
	CurrencyConvertorSvc_Currency_VEB,
	CurrencyConvertorSvc_Currency_VND,
	CurrencyConvertorSvc_Currency_YER,
	CurrencyConvertorSvc_Currency_YUM,
	CurrencyConvertorSvc_Currency_ZMK,
	CurrencyConvertorSvc_Currency_ZWD,
	CurrencyConvertorSvc_Currency_TRY,
} CurrencyConvertorSvc_Currency;
CurrencyConvertorSvc_Currency CurrencyConvertorSvc_Currency_enumFromString(NSString *string);
NSString * CurrencyConvertorSvc_Currency_stringFromEnum(CurrencyConvertorSvc_Currency enumValue);
@interface CurrencyConvertorSvc_ConversionRate : NSObject {
	
/* elements */
	CurrencyConvertorSvc_Currency FromCurrency;
	CurrencyConvertorSvc_Currency ToCurrency;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CurrencyConvertorSvc_ConversionRate *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (assign) CurrencyConvertorSvc_Currency FromCurrency;
@property (assign) CurrencyConvertorSvc_Currency ToCurrency;
/* attributes */
- (NSDictionary *)attributes;
@end
@interface CurrencyConvertorSvc_ConversionRateResponse : NSObject {
	
/* elements */
	NSNumber * ConversionRateResult;
/* attributes */
}
- (NSString *)nsPrefix;
- (xmlNodePtr)xmlNodeForDoc:(xmlDocPtr)doc elementName:(NSString *)elName elementNSPrefix:(NSString *)elNSPrefix;
- (void)addAttributesToNode:(xmlNodePtr)node;
- (void)addElementsToNode:(xmlNodePtr)node;
+ (CurrencyConvertorSvc_ConversionRateResponse *)deserializeNode:(xmlNodePtr)cur;
- (void)deserializeAttributesFromNode:(xmlNodePtr)cur;
- (void)deserializeElementsFromNode:(xmlNodePtr)cur;
/* elements */
@property (retain) NSNumber * ConversionRateResult;
/* attributes */
- (NSDictionary *)attributes;
@end
/* Cookies handling provided by http://en.wikibooks.org/wiki/Programming:WebObjects/Web_Services/Web_Service_Provider */
#import <libxml/parser.h>
#import "xsd.h"
#import "CurrencyConvertorSvc.h"
@class CurrencyConvertorSoapBinding;
@class CurrencyConvertorSoap12Binding;
@interface CurrencyConvertorSvc : NSObject {
	
}
+ (CurrencyConvertorSoapBinding *)CurrencyConvertorSoapBinding;
+ (CurrencyConvertorSoap12Binding *)CurrencyConvertorSoap12Binding;
@end
@class CurrencyConvertorSoapBindingResponse;
@class CurrencyConvertorSoapBindingOperation;
@protocol CurrencyConvertorSoapBindingResponseDelegate <NSObject>
- (void) operation:(CurrencyConvertorSoapBindingOperation *)operation completedWithResponse:(CurrencyConvertorSoapBindingResponse *)response;
@end
@interface CurrencyConvertorSoapBinding : NSObject <CurrencyConvertorSoapBindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(CurrencyConvertorSoapBindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (CurrencyConvertorSoapBindingResponse *)ConversionRateUsingParameters:(CurrencyConvertorSvc_ConversionRate *)aParameters ;
- (void)ConversionRateAsyncUsingParameters:(CurrencyConvertorSvc_ConversionRate *)aParameters  delegate:(id<CurrencyConvertorSoapBindingResponseDelegate>)responseDelegate;
@end
@interface CurrencyConvertorSoapBindingOperation : NSOperation {
	CurrencyConvertorSoapBinding *binding;
	CurrencyConvertorSoapBindingResponse *response;
	id<CurrencyConvertorSoapBindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) CurrencyConvertorSoapBinding *binding;
@property (readonly) CurrencyConvertorSoapBindingResponse *response;
@property (nonatomic, assign) id<CurrencyConvertorSoapBindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(CurrencyConvertorSoapBinding *)aBinding delegate:(id<CurrencyConvertorSoapBindingResponseDelegate>)aDelegate;
@end
@interface CurrencyConvertorSoapBinding_ConversionRate : CurrencyConvertorSoapBindingOperation {
	CurrencyConvertorSvc_ConversionRate * parameters;
}
@property (retain) CurrencyConvertorSvc_ConversionRate * parameters;
- (id)initWithBinding:(CurrencyConvertorSoapBinding *)aBinding delegate:(id<CurrencyConvertorSoapBindingResponseDelegate>)aDelegate
	parameters:(CurrencyConvertorSvc_ConversionRate *)aParameters
;
@end
@interface CurrencyConvertorSoapBinding_envelope : NSObject {
}
+ (CurrencyConvertorSoapBinding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface CurrencyConvertorSoapBindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
@class CurrencyConvertorSoap12BindingResponse;
@class CurrencyConvertorSoap12BindingOperation;
@protocol CurrencyConvertorSoap12BindingResponseDelegate <NSObject>
- (void) operation:(CurrencyConvertorSoap12BindingOperation *)operation completedWithResponse:(CurrencyConvertorSoap12BindingResponse *)response;
@end
@interface CurrencyConvertorSoap12Binding : NSObject <CurrencyConvertorSoap12BindingResponseDelegate> {
	NSURL *address;
	NSTimeInterval defaultTimeout;
	NSMutableArray *cookies;
	BOOL logXMLInOut;
	BOOL synchronousOperationComplete;
	NSString *authUsername;
	NSString *authPassword;
}
@property (copy) NSURL *address;
@property (assign) BOOL logXMLInOut;
@property (assign) NSTimeInterval defaultTimeout;
@property (nonatomic, retain) NSMutableArray *cookies;
@property (nonatomic, retain) NSString *authUsername;
@property (nonatomic, retain) NSString *authPassword;
- (id)initWithAddress:(NSString *)anAddress;
- (void)sendHTTPCallUsingBody:(NSString *)body soapAction:(NSString *)soapAction forOperation:(CurrencyConvertorSoap12BindingOperation *)operation;
- (void)addCookie:(NSHTTPCookie *)toAdd;
- (CurrencyConvertorSoap12BindingResponse *)ConversionRateUsingParameters:(CurrencyConvertorSvc_ConversionRate *)aParameters ;
- (void)ConversionRateAsyncUsingParameters:(CurrencyConvertorSvc_ConversionRate *)aParameters  delegate:(id<CurrencyConvertorSoap12BindingResponseDelegate>)responseDelegate;
@end
@interface CurrencyConvertorSoap12BindingOperation : NSOperation {
	CurrencyConvertorSoap12Binding *binding;
	CurrencyConvertorSoap12BindingResponse *response;
	id<CurrencyConvertorSoap12BindingResponseDelegate> delegate;
	NSMutableData *responseData;
	NSURLConnection *urlConnection;
}
@property (retain) CurrencyConvertorSoap12Binding *binding;
@property (readonly) CurrencyConvertorSoap12BindingResponse *response;
@property (nonatomic, assign) id<CurrencyConvertorSoap12BindingResponseDelegate> delegate;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;
- (id)initWithBinding:(CurrencyConvertorSoap12Binding *)aBinding delegate:(id<CurrencyConvertorSoap12BindingResponseDelegate>)aDelegate;
@end
@interface CurrencyConvertorSoap12Binding_ConversionRate : CurrencyConvertorSoap12BindingOperation {
	CurrencyConvertorSvc_ConversionRate * parameters;
}
@property (retain) CurrencyConvertorSvc_ConversionRate * parameters;
- (id)initWithBinding:(CurrencyConvertorSoap12Binding *)aBinding delegate:(id<CurrencyConvertorSoap12BindingResponseDelegate>)aDelegate
	parameters:(CurrencyConvertorSvc_ConversionRate *)aParameters
;
@end
@interface CurrencyConvertorSoap12Binding_envelope : NSObject {
}
+ (CurrencyConvertorSoap12Binding_envelope *)sharedInstance;
- (NSString *)serializedFormUsingHeaderElements:(NSDictionary *)headerElements bodyElements:(NSDictionary *)bodyElements;
@end
@interface CurrencyConvertorSoap12BindingResponse : NSObject {
	NSArray *headers;
	NSArray *bodyParts;
	NSError *error;
}
@property (retain) NSArray *headers;
@property (retain) NSArray *bodyParts;
@property (retain) NSError *error;
@end
