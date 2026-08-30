class Twitter {
public:
    vector<pair<int , int>> post;
    unordered_map<int , unordered_set<int>> following ; // mapping follower to followees 
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        /*Compose a new id tweetID */
        post.push_back({userId, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = 0;
        vector<int> res{};

        for (int i = post.size() - 1 ; i >= 0;i--){
            auto [user , tweet] = post[i];

            if (user == userId || following[userId].count(user)){
                res.push_back(tweet);
                n++;
                if (n == 10) break;
            }
            
        }

        return res ;
        
    }
    
    void follow(int followerId, int followeeId) {
        // follow that means followerid -> followeeid
        following[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        // means erase followerId , followeeId 
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */