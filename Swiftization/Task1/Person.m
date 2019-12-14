//
//  DataProvider.m
//  Swiftization
//
//  Created by Alexey Puzankov on 13/12/2019.
//  Copyright © 2019 Alexey Puzankov. All rights reserved.
//

#import "Person.h"

@implementation Person

- (instancetype)initWithName:(NSString*)name
{
	assert(name != nil);
	
	return [self initWithName:name age:20];
}

- (instancetype)initWithName:(NSString*)name age:(NSInteger)age
{
	assert(name != nil);
	
	self = [super init];
	
	_name = [name copy];
	_age = age;
	
	return self;
}

- (NSString *)fullname
{
	if (_surname == nil) {
		return [_name copy];
	}
	return [_name stringByAppendingString:_surname];
}

- (Location)location
{
	Location loc = {10.0, 20.0};
	return loc;
}

#pragma mark - NSCopying

- (nonnull id)copyWithZone:(nullable NSZone *)zone {
	return [[Person alloc] initWithName:_name
									age:_age];
}

@end


