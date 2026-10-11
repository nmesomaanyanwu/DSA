class Solution {

public:
    double myPow(double x, int n) {
        long long expo = n;
        
        if (n < 0){
            expo = - expo;
        }

        auto rec = [&](auto&& self ,double base , long long  i) -> double{

            if (x == 0) return 0;
            if (i == 0) return 1.0;

             double res = self(self , base ,  i/2);
         

            if (i % 2 == 1){
                return res = base * res * res;
            }

            return res * res;
        };


        double result = rec(rec, x, expo);
        return n < 0 ? 1.0 / result : result;
       
    }
};