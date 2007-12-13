/*
 *  RTMSession.h
 *  
 *  Copyright 2007 Brian Moore. All rights reserved.
 *
 *  This file is part of QSRememberTheMilk.
 *
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, 
 *      this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright 
 *      notice, this list of conditions and the following disclaimer in the 
 *      documentation and/or other materials provided with the distribution.
 *  * Neither the name of Binary Minded Software nor the names of its 
 *      contributors may be used to endorse or promote products derived from 
 *      this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 *  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#import <Cocoa/Cocoa.h>

#define kRTMTaskNameKey @"name"
#define kRTMTaskDueDateKey @"duedate"
#define kRTMTaskHasDueTimeKey @"hasduetime"

@class RTMResponse;
@interface RTMSession : NSObject {
    NSString *m_token;
    NSString *m_timeline;
    
    RTMResponse *m_cachedListsResponse;
    NSDate *m_cachedListsCreationTime;
    
    BOOL m_expired;
}

- (id)initWithToken:(NSString *)token;

- (NSString *)token;

// this is set only after an erroneous method call is made
- (BOOL)hasExpired;

- (NSString *)createTimeline;
- (NSString *)getTimeline;

- (NSArray *)getLists;

- (RTMResponse *)callAndVerifyAuthenticatedMethod:(NSString *)method 
                                    withArguments:(NSDictionary *)dict
                                            error:(NSString **)error;

- (NSDictionary *)addTask:(NSString *)todo toList:(NSDictionary *)list parse:(BOOL)parse error:(NSString **)err;

@end
