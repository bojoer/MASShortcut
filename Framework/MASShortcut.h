#import "MASKeyCodes.h"

/**
 A model class to hold a key combination.

 This class just represents a combination of keys. It does not care if
 the combination is valid or can be used as a hotkey, it doesn’t watch
 the input system for the shortcut appearance, nor it does access user
 defaults.
*/
@interface MASShortcut : NSObject <NSSecureCoding, NSCopying>

/**
 The virtual key code for the keyboard key.

 Hardware independent, same as in `NSEvent`. See `Events.h` in the HIToolbox
 framework for a complete list, or Command-click this symbol: `kVK_ANSI_A`.
*/
@property (nonatomic, readonly) NSUInteger keyCode;

/**
 Cocoa keyboard modifier flags.

 Same as in `NSEvent`: `NSCommandKeyMask`, `NSAlternateKeyMask`, etc.
*/
@property (nonatomic, readonly) NSUInteger modifierFlags;

/**
 Same as `keyCode`, just a different type.
*/
@property (nonatomic, readonly) UInt32 carbonKeyCode;

/**
 Carbon modifier flags.

 A bit sum of `cmdKey`, `optionKey`, etc.
*/
@property (nonatomic, readonly) UInt32 carbonFlags;

/**
 A string representing the “key” part of a shortcut, like the `5` in `⌘5`.
*/
@property (nonatomic, readonly) NSString *keyCodeString;

/**
 A key-code string used in key equivalent matching.

 For precise meaning of “key equivalents” see the `keyEquivalent`
 property of `NSMenuItem`. Here the string is used to support shortcut
 validation (“is the shortcut already taken in this menu?”) and
 for display in `NSMenu`.
*/
@property (nonatomic, readonly) NSString *keyCodeStringForKeyEquivalent;

/**
 A string representing the shortcut modifiers, like the `⌘` in `⌘5`.
*/
@property (nonatomic, readonly) NSString *modifierFlagsString;

- (instancetype)initWithKeyCode:(NSUInteger)code modifierFlags:(NSUInteger)flags;
+ (instancetype)shortcutWithKeyCode:(NSUInteger)code modifierFlags:(NSUInteger)flags;

/**
 Creates a new shortcut from an `NSEvent` object.

 This is just a convenience initializer that reads the key code and modifiers from an `NSEvent`.
*/
+ (instancetype)shortcutWithEvent:(NSEvent *)anEvent;

@end
