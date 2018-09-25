//
//  main.swift
//  SwiftSort
//
//  Created by liyoucheng on 2018/7/10.
//  Copyright © 2018年 liyoucheng. All rights reserved.
//

import Foundation

func testSort(sortObject: SortType) {
    let list: Array<Int> = [62, 88, 58, 47, 62, 35, 73, 51, 99, 37, 93]
    let sortList = sortObject.sort(items: list)
    print(sortList)
    print("\n\n\n\n")
}
//
//class MyCustomer {
//    let name: String
//    let orders: Array<Int>
//
//    init(name: String, orders: Array<Int>) {
//        self.name = name
//        self.orders = orders
//    }
//
//    func printOwing() {
//        print("***********************************")
//        print("********** Custome Owes ***********")
//        print("***********************************")
//
//        var outstanding: Int = 0
//        for order in orders {
//            outstanding += order
//        }
//
//        print("name:\(self.name)")
//        print("amount:\(outstanding)")
//    }
//}

//重构后
class MyCustomer {
    let name: String
    let orders: Array<Int>
    
    init(name: String, orders: Array<Int>) {
        self.name = name
        self.orders = orders
    }
    
    func printOwing() {
        printBanner()
        printDetail(outstanding: getOutStanding())
    }
    
    func printBanner() {
        print("***********************************")
        print("********** Custome Owes ***********")
        print("***********************************")
    }
    
    func getOutStanding() -> Int {
        var outstanding: Int = 0
        for order in orders {
            outstanding += order
        }
        
        return outstanding;
    }
    
    func printDetail(outstanding: Int) {
        print("name:\(self.name)")
        print("amount:\(outstanding)")
    }
}

let myCustome: MyCustomer = MyCustomer(name: "Liyoucheng", orders: [10,20,30,40,50])
myCustome.printOwing()
//http://www.cnblogs.com/ludashi/p/6031379.html
//http://www.cnblogs.com/ludashi/p/6043006.html
//http://www.cnblogs.com/ludashi/p/6051871.html
//http://www.cnblogs.com/ludashi/p/6051912.html
//http://www.cnblogs.com/ludashi/p/6069807.html

//testSort(sortObject: BubbleSort())
//testSort(sortObject: InsertSort())
//testSort(sortObject: SimpleSelectionSort())
//testSort(sortObject: ShellSort())
//testSort(sortObject: HeapSort())
//testSort(sortObject: MergingSort())
//testSort(sortObject: QuickSort())
//testSort(sortObject: RadixSort())

