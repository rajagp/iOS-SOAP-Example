/*
 *  AppDelegate.h
 *  SoapTest
 *
 *  Created by Priya Rajagopal on 9/21/12.
 *  Copyright (c) 2012 Lunaria Software,LLC. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "ViewController.h"
#import "CurrencyConvertorSvc.h"

@interface ViewController ()

@end

@implementation ViewController

#pragma mark - view life cycle
- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UI Event Handlers
- (IBAction)onConvertClicked:(id)sender {
    if (!self.fromCurrencyTextField.text.length || !self.toCurrencyTextField.text.length)
    {
        UIAlertView* alert = [[UIAlertView alloc]initWithTitle:NSLocalizedString(@"Invalid Parameters",nil)message:NSLocalizedString(@"Please enter valid from and to currency types and try again",nil) delegate:self cancelButtonTitle:NSLocalizedString(@"OK",nil) otherButtonTitles: nil];
        [alert show];
        return;
    }
    [self.activityIndicator setHidden:NO];
    [self.activityIndicator startAnimating];
    [self processRequest];
    
}



#pragma mark - TextField Delegate
- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
    
}

#pragma mark - Web Services Processing

-(void)processRequest
{
    CurrencyConvertorSoapBinding* binding = [CurrencyConvertorSvc CurrencyConvertorSoapBinding];
    CurrencyConvertorSoapBindingResponse* response;
    CurrencyConvertorSvc_ConversionRate* request = [[CurrencyConvertorSvc_ConversionRate alloc]init];
    request.FromCurrency =  CurrencyConvertorSvc_Currency_enumFromString(self.fromCurrencyTextField.text);
    request.ToCurrency = CurrencyConvertorSvc_Currency_enumFromString(self.toCurrencyTextField.text );
    response = [binding ConversionRateUsingParameters:request];

    dispatch_async(dispatch_get_main_queue(), ^{
        [self processResponse:response];
    });
}

-(void) processResponse :(CurrencyConvertorSoapBindingResponse*)soapResponse
{
    NSArray *responseBodyParts = soapResponse.bodyParts;
    id bodyPart;
    [self.activityIndicator stopAnimating];
    
    @try{
        bodyPart = [responseBodyParts objectAtIndex:0]; // Assuming just 1 part in response which is fine
        
    }
    @catch (NSException* exception)
    {
        UIAlertView* alert = [[UIAlertView alloc]initWithTitle:NSLocalizedString(@"Server Error" ,nil)message:NSLocalizedString(@"Error while trying to process request",nil) delegate:self cancelButtonTitle:NSLocalizedString(@"OK",nil) otherButtonTitles: nil];
        [alert show];
        return;
    }
    
    if ([bodyPart isKindOfClass:[SOAPFault class]]) {
        
        NSString* errorMesg = ((SOAPFault *)bodyPart).simpleFaultString;
        UIAlertView* alert = [[UIAlertView alloc]initWithTitle:NSLocalizedString(@"Server Error",nil) message:errorMesg delegate:self cancelButtonTitle:NSLocalizedString(@"OK",nil) otherButtonTitles: nil];
        [alert show];
    }
    else if([bodyPart isKindOfClass:[CurrencyConvertorSvc_ConversionRateResponse class]]) {
        CurrencyConvertorSvc_ConversionRateResponse* rateResponse = bodyPart;
        UIAlertView* alert = [[UIAlertView alloc]initWithTitle:NSLocalizedString(@"Success!",nil) message:[NSString stringWithFormat:NSLocalizedString(@"Currency Conversion Rate is %@",nil),rateResponse.ConversionRateResult] delegate:self cancelButtonTitle:NSLocalizedString(@"OK",nil)otherButtonTitles: nil];
        [alert show];
       
    }
    
}
@end
