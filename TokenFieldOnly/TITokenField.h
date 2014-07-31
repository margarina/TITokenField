//
//  TITokenField.h
//  TITokenField
//
//  Created by Tom Irving on 16/02/2010.
//  Copyright 2012 Tom Irving. All rights reserved.
//
//	Redistribution and use in source and binary forms, with or without modification,
//	are permitted provided that the following conditions are met:
//
//		1. Redistributions of source code must retain the above copyright notice, this list of
//		   conditions and the following disclaimer.
//
//		2. Redistributions in binary form must reproduce the above copyright notice, this list
//         of conditions and the following disclaimer in the documentation and/or other materials
//         provided with the distribution.
//
//	THIS SOFTWARE IS PROVIDED BY TOM IRVING "AS IS" AND ANY EXPRESS OR IMPLIED
//	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TOM IRVING OR
//	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//	ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <UIKit/UIKit.h>

@class TITokenField, TIToken;

//==========================================================
#pragma mark - Delegate Methods -
//==========================================================
@protocol TITokenFieldDelegate <UITextFieldDelegate>
@optional
- (BOOL)tokenField:(TITokenField *)tokenField willAddToken:(TIToken *)token;
- (void)tokenField:(TITokenField *)tokenField didAddToken:(TIToken *)token;
- (BOOL)tokenField:(TITokenField *)tokenField willRemoveToken:(TIToken *)token;
- (void)tokenField:(TITokenField *)tokenField didRemoveToken:(TIToken *)token;

- (void)tokenField:(TITokenField *)tokenField heightWillChange:(CGFloat)newHeight;

@end

@interface TITokenFieldInternalDelegate : NSObject <UITextFieldDelegate>
@end

//==========================================================
#pragma mark - TITokenField -
//==========================================================
typedef enum {
	TITokenFieldControlEventFrameWillChange = 1 << 24,
	TITokenFieldControlEventFrameDidChange = 1 << 25,
} TITokenFieldControlEvents;

@interface TITokenField : UITextField
@property (nonatomic, weak) id <TITokenFieldDelegate> delegate;
@property (weak, nonatomic, readonly) NSArray * tokens;
@property (weak, nonatomic, readonly) TIToken * selectedToken;
@property (weak, nonatomic, readonly) NSArray * tokenTitles;
@property (weak, nonatomic, readonly) NSArray * tokenObjects;
@property (weak, nonatomic) NSLayoutConstraint *tokenFieldHeightConstraint;
@property (nonatomic, assign) CGFloat animationDuration;
@property (nonatomic, assign) BOOL clearsTextOnEndEditing;
@property (nonatomic, assign) BOOL editable;
@property (nonatomic, assign) BOOL resultsModeEnabled;
@property (nonatomic, assign) BOOL removesTokensOnEndEditing;
@property (nonatomic, readonly) int numberOfLines;
@property (nonatomic) int tokenLimit;
@property (nonatomic, strong) NSCharacterSet * tokenizingCharacters;

- (void)addToken:(TIToken *)title;
- (TIToken *)addTokenWithTitle:(NSString *)title;
- (TIToken *)addTokenWithTitle:(NSString *)title representedObject:(id)object;
- (void)addTokensWithTitleList:(NSString *)titleList;
- (void)addTokensWithTitleArray:(NSArray *)titleArray;
- (void)removeToken:(TIToken *)token;
- (void)removeAllTokens;

- (void)selectToken:(TIToken *)token;
- (void)deselectSelectedToken;

- (void)tokenizeText;

- (void)layoutTokensAnimated:(BOOL)animated;
- (void)setResultsModeEnabled:(BOOL)enabled animated:(BOOL)animated;

// Pass nil to hide label
- (void)setPromptText:(NSString *)aText;

- (CGFloat)calculateSingleRowHeight;

@end

//==========================================================
#pragma mark - TIToken -
//==========================================================
typedef enum {
	TITokenAccessoryTypeNone = 0, // Default
	TITokenAccessoryTypeDisclosureIndicator = 1,
} TITokenAccessoryType;

@interface TIToken : UIControl
@property (nonatomic, copy) NSString * title;
@property (nonatomic, strong) id representedObject;
@property (nonatomic, strong) UIFont * font;
@property (nonatomic, strong) UIColor * textColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor * highlightedTextColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor * tintColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, assign) TITokenAccessoryType accessoryType;
@property (nonatomic, assign) CGFloat maxWidth;

- (instancetype)initWithTitle:(NSString *)aTitle;
- (instancetype)initWithTitle:(NSString *)aTitle representedObject:(id)object;
- (instancetype)initWithTitle:(NSString *)aTitle representedObject:(id)object font:(UIFont *)aFont;

+ (UIColor *)blueTintColor;
+ (UIColor *)redTintColor;
+ (UIColor *)greenTintColor;

@end
