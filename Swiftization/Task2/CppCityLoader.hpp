//
//  CityLoader.hpp
//  Swiftization
//
//  Created by Alexey Puzankov on 13/12/2019.
//  Copyright © 2019 Alexey Puzankov. All rights reserved.
//

#ifndef CityLoader_hpp
#define CityLoader_hpp

#include <stdio.h>
#include <string>
#include <vector>

typedef struct CppCity
{
private:
	std::string name;
	long age;
	
public:
	
	CppCity(std::string name, long age) {
		this->name = name;
		this->age = age;
	}
	
	std::string getName() {
		return name;
	}
	
	long getAge() {
		return age;
	}
	
} CppCity;

class CppCityLoader
{
public:
	CppCityLoader() {
		//do nothing
	}
	
	std::vector<CppCity> loadCities() {
		auto vector = std::vector<CppCity>();
		auto city = CppCity {"some name", 11};
		vector.push_back(city);
		return vector;
	}
};

#endif /* CityLoader_hpp */
