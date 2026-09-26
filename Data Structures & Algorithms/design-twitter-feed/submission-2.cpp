auto cmp = [](const array<int, 2>& p1, const array<int, 2>& p2) {
    return p1[1] > p2[1]; 
}; 

class Twitter {
public:
   
    int time; // to store tweet Id in order
    unordered_map<int,unordered_map<int,bool>> followees; // followees[user_id] = the user that user_id follows
    unordered_map<int,priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)>> posts;// posts[user_id] = the 10 most recents posts of user_id 
    // array<int, 2> -> [0] is Tweet id and [1] is the timeStamp

    Twitter() {
        auto cmp = [](const array<int, 2>& p1, const array<int, 2>& p2) {
            return p1[1] > p2[1]; 
        }; 

        time = 0;
        followees = {};
        posts = {};
    }
    
    void postTweet(int userId, int tweetId) {
        //cout << "userId = " << userId << " - tweetId = " << tweetId << "\n"; 
        array<int, 2> post = {tweetId, time++};
        posts[userId].push(post);
        if (posts[userId].size() > 10) posts[userId].pop();
    }
    
    vector<int> getNewsFeed(int userId) {
        followees[userId][userId] = true;
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(cmp)> feed;
        // we want the 10 most recent post from
        // we need to go through every followees of userId and find the 10 most recent post
        int numberOfPost;
        for (auto& [foloowee, _] : followees[userId]) {
            
            if (_ == false) continue;

            numberOfPost = posts[foloowee].size();
            auto hisPosts = posts[foloowee];

            for (int i = 0; i < numberOfPost; i++) {
                //cout << "foloowee = " << foloowee << " - i = " << i << "\n"; 
                array<int, 2> post = hisPosts.top(); // the latest post 
                if (feed.size() < 10) feed.push(post);
                else if (feed.top()[1] < post[1]) {
                    feed.pop();
                    feed.push(post);
                }
                hisPosts.pop();
            }
        }

        numberOfPost = feed.size();
        vector<int> output(numberOfPost);
        //cout << "numberOfPost = " << numberOfPost << "\n";
        for (int i = 0; i < numberOfPost; i++) {
            output[numberOfPost-i-1] = feed.top()[0];
            feed.pop();
        }

        return output;

    } 
    
    void follow(int followerId, int followeeId) {
        followees[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId][followeeId] = false;
    }
};
