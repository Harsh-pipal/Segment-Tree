class segTree{
    vector<int>seg;
public:
    segTree(int n){
        seg.resize(4*n + 1);
    }

    void build(int ind, int low, int high, vector<int>&arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = max(seg[2*ind+1] , seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r, vector<int>&arr){
        // lies completely inside
        if(low>=l && high<=r){
            return seg[ind];
        }

        // lies outside
        if(high<l || low>r){
            return INT_MIN;          //change as per requirements
        }

        // partially lies in the range
        int mid = (low + high)/2;
        
        int left = query(2*ind+1,low,mid,l,r,arr);
        int right = query(2*ind+2,mid+1,high,l,r,arr);

        return max(left,right);
    }

    void update(int ind, int low, int high, int changeInd, int value){

        if(low == high){
            seg[ind] = value;
            return;
        }

        int mid = (low + high)/2;
        if(ind <= mid)
            update(2*ind+1,low,mid,changeInd,value);
        else
            update(2*ind+2,mid+1,high,changeInd,value);

        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }

};
