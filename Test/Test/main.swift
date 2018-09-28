//
//  main.swift
//  Test
//
//  Created by liyoucheng on 2018/9/28.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

import Foundation

let stringArray = ["Objective-C", "Swift", "HTML", "CSS", "JavaScript", ""]
let stringDictionary = [ "b": "liyou","c": "shixiao","a": "zhude","d": "dege" ]

let ret = stringDictionary.sorted { (t1, t2) -> Bool in
    return t1.key > t2.key
}

let ret2 = ret.compactMap{
    return $0.key + "=" + $0.value
    }.reduce("", {
        return $0 == "" ? $1 : $0 + "&" + $1
    })

//let ret3 = ret2.reduce("", {
//    return $0 == "" ? $1 : $0 + "&" + $1
//})

print(ret2)

//let arr6 = stringDictionary.flatMap{
//    return $0
//}
//print(arr6)



//let ret3 = ret1.compactMap{
//    return $0.key + "=" + $0.value
//}

//let ret2 = ret1.reduce("", {
//    return $0.0 == "" ? $1 : $0 + "&" + $1
//})
//print(ret3)

//let array3 = ret1.reduce("", {
//    return $0 == "" ? $1 : $0 + "&" + $1
//})

//map
//func stringCount(string: String) -> Int {
//    return string.count
//}
//let ret = stringArray.map(stringCount)
//print(ret)
//
//let ret1 = stringArray.map{
//    return $0.count
//}
//print(ret1)
//
////flatMap
//let arr1 = stringArray.map{a->Int? in
//    let length = a.count
//    guard length > 0 else {
//        return nil
//    }
//    return length
//}
//print(arr1)
//
//let arr2 = stringArray.flatMap{ a->Int? in
//    let length = a.count
//    guard length > 0 else {
//        return nil
//    }
//    return length
//}
//print(arr2)
//
//let arr3 = [[1,2,3],[4,5,6],[7,8,9]]
//let arr4 = arr3.map{
//    $0
//}
//print(arr4)
//
//let arr5 = arr3.flatMap{
//    $0
//}
//print(arr5)
//
////compactMap
//let fruits = ["Apple", "Orange", "Puple"]
//let counts = [2,3,5]
//let array1 = counts.flatMap{ count in
//    fruits.map({ fruit in
//        return fruit + "\(count)"
//    })
//}
//print(array1)
//
//let array2 = stringArray.filter{
//    return $0.count < 10
//}
//print(array2)
//
//
//let array3 = stringArray.reduce("", {
//    return $0 == "" ? $1 : $0 + "&" + $1
//})
//print(array3)



