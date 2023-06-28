class Message {
    
    var title: String?
    var message: String?
    
    init(json: NSDictionary) {
        self.title = json["title"] as? String
        self.message = json["message"] as? String
    }
}
