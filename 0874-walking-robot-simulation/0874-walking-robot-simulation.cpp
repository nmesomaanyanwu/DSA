class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        vector<pair<int , int>> points; // keep tracks of points  
        vector<bool> positions = {true , false , false , false};
        /*
                index 0 - North 
                index 1 - south 
                index 2 - east 
                index 3 - west 
        */
        pair<int,int> start = {0, 0}; // this is the position the robot starts from 

        // we firstly iterate throught the commands  
        // if the move 
        unordered_set<pair<int, int>, PairHash> obs; // keep the obstacles 

        for (auto o : obstacles){
            obs.insert({o[0], o[1]});
        }

        for (int i = 0 ; i < commands.size(); i++){
        
            //for current position  we need to check 
            // if its -1 - turn right or -2 turn left 

            if (commands[i] == -1){
                // this means we need to turn right 
                if (positions[0]){ // if it was first north
                    positions[0] = false;
                    positions[2] = true;
                }
                else if (positions[1]){ // if it was first south
                    positions[1] = false;
                    positions[3] = true;

                }
                else if (positions[2]){// if it was first east
                    positions[2] = false;
                    positions[1] = true;

                }
                else if (positions[3]){ // if it was first west
                    positions[3] = false;
                    positions[0] = true;
                }
            }
            else if (commands[i] == -2){
                // this means we need to turn left 
                if (positions[0]){ // if it was first north
                    positions[0] = false;
                    positions[3] = true;

                }
                else if (positions[1]){ // if it was first south
                    positions[1] = false;
                    positions[2] = true;

                }
                else if (positions[2]){// if it was first east
                    positions[2] = false;
                    positions[0] = true;
                }
                else if (positions[3]){ // if it was first west
                    positions[3] = false;
                    positions[1] = true;
                }
            }
            else{
                // now we have our start position 
                // we have to check if adding are new command in its direction is ok or if theres an obstacle {x, y}

                if (positions[0]){
                    // if it north that means we do +y
                    int c = commands[i];
                    
                    for (int i = 1 ; i <= c ; i++){
                        if (i == c && obs.count({start.first , start.second + i}) == 0 ){
                            start = {start.first , start.second + c};
                        }
                        else if (obs.count({start.first , start.second + i}) == 1){
                            start = {start.first , start.second + i -1};
                            break;
                        }
                    }

                    points.push_back(start);

                }
                else if (positions[1]){
                    // if its south we  -Y
                    int c = commands[i];
                    
                    for (int i = 1 ; i <= c ; i++){
                        if (i == c && obs.count({start.first , start.second - i}) == 0 ){
                            start = {start.first , start.second - c};
                        }
                        else if (obs.count({start.first , start.second - i}) == 1){
                            start = {start.first , start.second - i +1};
                            break;
                        }
                    }

                    points.push_back(start);

                }
                else if (positions[2]){
                    // if its east we do + x 
                    int c = commands[i];
                    
                    for (int i = 1 ; i <= c ; i++){
                        if (i == c && obs.count({start.first + i , start.second}) == 0 ){
                            start = {start.first + c, start.second};
                        }
                        else if (obs.count({start.first + i , start.second}) == 1){
                            start = {start.first + i - 1 , start.second};
                            break;
                        }
                    }

                    points.push_back(start);

                }
                else if (positions[3]){
                    // if its west we do -x 

                    int c = commands[i];
                    
                    for (int i = 1 ; i <= c ; i++){
                        if (i == c && obs.count({start.first - i, start.second}) == 0 ){
                            start = {start.first - c, start.second};
                        }
                        else if (obs.count({start.first - i , start.second}) == 1){
                            start = {start.first - i + 1 , start.second};
                            break;
                        }
                    }

                    points.push_back(start);


                }


            }
        
        }


        // now we should have our final poins list so 
        int max_count = 0 ;

        for (auto [x , y] : points){
            int a = abs(x)* abs(x);
            int b = abs(y)* abs(y);

            max_count = max(max_count , a + b);
        }
        
        return max_count;

    }


};