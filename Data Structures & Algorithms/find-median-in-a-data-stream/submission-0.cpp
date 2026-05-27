class MedianFinder {
    double median;
    vector<int> arr;
    int size;
public:
    MedianFinder() {
        median = -1;
        size = 0;
    }
    
    void addNum(int num) {
        this->arr.push_back(num);
        sort(arr.begin(),arr.end());
        size++;
        if(size%2){
            median = arr[size/2];
        }
        else{
            median = (arr[size/2-1] + arr[size/2])/2.0;
        }
        
    }
    
    double findMedian() {
        return median;
    }
};
