import UIKit

class ThriftyThreads {

    // MARK: Properties

    //Properties for the app structure
    let appDelegate: AppDelegate
    let applicationNavigationController: UINavigationController

    //Properties containing the list of categories
    var categoryList: [Category] = []

    //Properties for the current view displayed to the user
    var currentView: UIViewController

    // MARK: Initialization

    init() {
        self.appDelegate = UIApplication.shared.delegate as! AppDelegate

        //Initialize the list of categories
        self.categoryList = [Category(name:"Clothing", items:[Item(name: "T-Shirts"),
                                                            Item(name: "Jeans"),
                                                            Item(name: "Dresses")]),
                            Category(name:"Accessories", items:[Item(name: "Hats"),
                                                               Item(name: "Belts"),
                                                               Item(name: "Sunglasses")]),
                            Category(name:"Shoes", items:[Item(name: "Sneakers"),
                                                         Item(name: "Boots"),
                                                         Item(name: "Sandals")]),
                            Category(name:"Luggage", items:[Item(name: "Backpacks"),
                                                           Item(name: "Totes"),
                                                           Item(name: "Duffel Bags")])]

        //Create the initial view and initialize the navigation controller
        let initialView = CategoryTableViewController(style: .grouped)
        initialView.title = "Thrifty Threads"
        self.applicationNavigationController = UINavigationController(rootViewController: initialView)
        self.applicationNavigationController.navigationBar.prefersLargeTitles = true
        self.currentView = self.applicationNavigationController.topViewController!
    }

    // MARK: Helper Methods

    //Method to present the view controller
    func presentView() {
        self.appDelegate.window?.rootViewController = self.applicationNavigationController
    }

    //Method to push a new view controller onto the navigation stack
    func goToView(view: UIViewController) {
        self.applicationNavigationController.pushViewController(view, animated: true)
        self.currentView = self.applicationNavigationController.topViewController!
    }

    //Method to get a list of categories and items
    func getCategoryListData() -> [Category] {
        return self.categoryList
    }

}