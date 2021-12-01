/* **********版权声明**********
 Copyright @ 2021 王晓腾（自动化学院，SEU） All rights reserved.
 email: wangxiaoteng0628@163.com
  **********请尊重知识********** */
vector<int> merge_sort(vector<int>& arr) {
    int length = arr.size();
    int N = get_2_N(length);
    int up_bound = pow(2, N);
    for (int i = 2; i <= up_bound; i = i * 2) {//确定每一次排序的元素个数
        for (int j = 0; j < (length + i - 1) / i; j++) {//在特定待排序元素个数的情况下，确定总共有多少个小块需要排序
            //对每一个小块进行排序
            //对位于begin--end之间的元素进行归并
            int begin = 0 + j * i;
            int end = i - 1 + j * i;
            int mid = i / 2;//确定中间值
            if (begin + mid > length - 1) {//最后剩下的尾巴只有前半块，无需排序
                continue;
            }
            int kh = 0, kr = mid;//前半块指针、后半块指针
            int end_ = min(end, length - 1);//放置数组越界

            //拷贝待排序块
            vector<int> temp(arr.begin() + begin, arr.begin() + end_+1);
            int k = begin;//往哪一个位置放元素
            while (kh < mid && kr <= end_) {
                if (temp[kh] <= temp[kr]) {
                    arr[k] = temp[kh];
                    kh++;
                    k++;
                    if (kh == mid) {//前半块放完，接下来只放后半块
                        break;
                    }
                }
                else {
                    arr[k] = temp[kr];
                    kr++;
                    k++;
                    if (kr > end_ - begin) {//后半块放完，接下来只放前半块
                        for (int k_left = kh; k_left < mid; k_left++) {
                            arr[k] = temp[k_left];
                            k++;
                        }
                        break;
                    }
                }
            }
        }
    }
    return arr;
}
