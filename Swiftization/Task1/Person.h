//
//  DataProvider.h
//  Swiftization
//
//  Created by Alexey Puzankov on 13/12/2019.
//  Copyright © 2019 Alexey Puzankov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PersonType) {
	PersonTypeGood,
	PersonTypeBad
};

typedef struct Location {
	CGFloat altitude;
	CGFloat longitude;
} Location;

@interface Person : NSObject<NSCopying>

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, strong, nullable) NSString *surname;
@property (nonatomic, strong, readonly) NSString *fullname;
@property (nonatomic, assign, readonly) NSInteger age;
@property (nonatomic, assign) PersonType personType;
@property (nonatomic, readonly) Location location;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString*)name;
- (instancetype)initWithName:(NSString*)name age:(NSInteger)age NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
