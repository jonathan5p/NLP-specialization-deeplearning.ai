""" Provided a list of meeting times, merge list to single meeting array. 
Input: [[14,16], [9,10], [13,15], [8,12], [11, 12]] Illustration: 
8                  
12 --------------------- 9    
10   11   12 -------   ------- 13          
15 -------------- 14            
16 ---------------- Output: [[8, 12], [13, 16]] """

def merging_meetings(meeting_intervals):
    output_intervals = []
    sorted_list = sorted(meeting_intervals,key=lambda x:x[0])
    print(sorted_list)
    for cur_interval in sorted_list: 
        cur_interval_min, cur_interval_max = cur_interval
        if len(output_intervals)==0:
            output_intervals.append(cur_interval)
        else:
            count = 0
            for i in range(len(output_intervals)):
                cur_output_interval = output_intervals[i]
                cur_out_interval_min, cur_out_interval_max = cur_output_interval
                if cur_interval_min < cur_out_interval_max and cur_interval_max>cur_out_interval_max:
                    output_intervals[i] = [cur_out_interval_min,cur_interval_max]
                elif cur_interval_min > cur_out_interval_max and cur_interval_max>cur_out_interval_max:
                    count+=1
            if count==len(output_intervals):
                output_intervals.append(cur_interval)
        print('out list: ',output_intervals)
    return output_intervals

test_list = [[14,16], [9,10], [13,15], [8,12], [11, 12]]
print(merging_meetings(test_list))

