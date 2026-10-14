class Solution {
public:
    void merge(vector<int>& nums,int st,int mid,int end){
        int i=st,j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=end){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
                temp.push_back(nums[i]);
                i++;
        }
        while(j<=end){
                temp.push_back(nums[j]);
                j++;
        }
        for(int i = 0 ; i<temp.size();i++){
            nums[i+st] = temp[i];
        }
    }
    void mergeSort(vector<int>& nums,int st,int end){
        if(st < end){
            int mid = st +(end-st)/2;
            mergeSort(nums,st,mid); //lefft half
            mergeSort(nums,mid+1,end); //right half

            merge(nums,st,mid,end);    
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};