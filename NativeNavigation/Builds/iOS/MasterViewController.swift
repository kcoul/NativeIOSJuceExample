//
//  MasterViewController.swift
//  JustTuner
//
//  Created by Adam Elemental on 15/09/2015.
//
//

import UIKit

class MasterViewController: UITableViewController
{
    @objc var juceViewController: JuceViewController?
    var messages = [Message]()
    

    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.title = "Messages"
        self.tableView.dataSource = self
        self.loadData()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func loadData() {
        print ("loadData");
        let dataController = DataControllerObjC()
        let jsonString = dataController.getJsonData()
        print (jsonString ?? "")
        
        let jsonData = jsonString?.data(using: String.Encoding.utf8)
        
        if let jsonData = jsonData {
            do {
                let jsonDictionary = try JSONSerialization.jsonObject(with: jsonData, options: .allowFragments)
                print("Dictionary received")
                
                if let jsonArray = jsonDictionary as? NSArray {
                    for item in jsonArray {
                        messages.append(Message(json: item as! NSDictionary));
                    }
                    print (messages.debugDescription);
                }
            }
            catch let error as NSError {
                print(error)
            }
        }
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return messages.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell: UITableViewCell = UITableViewCell(style: UITableViewCellStyle.default, reuseIdentifier: "cell")
        
        if let message = self.messages[indexPath.row] as Message? {
            cell.textLabel!.text = message.title
        } else {
            cell.textLabel!.text = "Untitled"
        }
        
        return cell
        
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        let message = messages[indexPath.row]
        let dataController = DataControllerObjC()
        
        dataController.setMessage(message.title, message.message)
        juceViewController!.setTitle()

        if UIDevice.current.userInterfaceIdiom == .pad {
            if #available(iOS 8.0, *) {
                showDetailViewController(juceViewController!, sender: self)
            } else {
            }
        } else {
            self.navigationController?.pushViewController(juceViewController!, animated: true)
        }

    }
    

    

}