//
//  ViewController.swift
//  Swiftization
//
//  Created by Alexey Puzankov on 13/12/2019.
//  Copyright © 2019 Alexey Puzankov. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
	
	private var personProvider: PersonProvider?
	private var swiftCityLoader = SwiftCityLoader()

	override func viewDidLoad() {
		super.viewDidLoad()
		
		let t = swiftCityLoader.loadCities()
		
		personProvider = PersonProvider(output: self)
		
		let firstPerson = personProvider?.firstPerson()
		let persons: [Person] = personProvider?.persons() as? [Person] ?? [];
		personProvider?.addPerson(Person(name: "Kevin Lomax"))
		personProvider?.loadPersons { persons in
			//do nothing
		}
		personProvider?.loadPersons()
		
	}
}

extension ViewController: IPersonProviderOutput
{
	func onPersonsLoaded(_ persons: [Person]) {
		//do nothing
	}
}

