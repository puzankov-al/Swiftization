//
//  PersonProvider.h
//  Swiftization
//
//  Created by Alexey Puzankov on 13/12/2019.
//  Copyright © 2019 Alexey Puzankov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"

NS_ASSUME_NONNULL_BEGIN

@protocol IPersonProviderOutput <NSObject>

- (void)onPersonsLoaded:(NSArray<Person *> *)persons;

@end

@protocol IPersonProvider <NSObject>

@property(nonatomic, weak) id<IPersonProviderOutput> output;

@end

@interface PersonProvider : NSObject<IPersonProvider>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithOutput:(id<IPersonProviderOutput>) output NS_DESIGNATED_INITIALIZER;

- (nullable Person *)firstPerson;
- (NSArray *)persons;
- (void)addPerson:(Person *)person;

- (void)loadPersons:(void(^)(NSArray<Person *> *))handler;
- (void)loadPersons;

@end

NS_ASSUME_NONNULL_END
