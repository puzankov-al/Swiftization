//
//  PersonProvider.m
//  Swiftization
//
//  Created by Alexey Puzankov on 13/12/2019.
//  Copyright © 2019 Alexey Puzankov. All rights reserved.
//

#import "PersonProvider.h"

@implementation PersonProvider
{
	NSMutableArray *persons;
}

@synthesize output = _output;

- (instancetype)initWithOutput:(id<IPersonProviderOutput>) output
{
	self = [super init];
	
	_output = output;
	
	persons = @[
				  [[Person alloc] initWithName:@"Thomas Anderson"],
				  [[Person alloc] initWithName:@"John Wick" age:30],
				  [[Person alloc] initWithName:@"John Constantine" age:34]
			].mutableCopy;
	
	return self;
}

- (Person *)firstPerson
{
	return [persons.firstObject copy];
}

- (NSArray *)persons
{
	return [persons copy];
}

- (void)addPerson:(Person *)person
{
	assert(person != nil);
	
	[persons addObject:person];
}

- (void)loadPersons:(void(^)(NSArray<Person *> *))handler
{
	assert(handler != nil);
	
	handler([persons copy]);
}

- (void)loadPersons
{
	[_output onPersonsLoaded:[persons copy]];
}

@end
