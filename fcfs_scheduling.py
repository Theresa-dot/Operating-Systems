process_queue = []
total_wtime = 0
total_tatime = 0
total_ctime = 0
n = int(input('Enter the total no of processes: '))
for i in range(n):
    process_queue.append([])  # append a list object to the list
    process_queue[i].append(input('Enter p_name: '))
    process_queue[i].append(int(input('Enter p_arrival: ')))
    process_queue[i].append(int(input('Enter p_bust: ')))
    process_queue[i].append(0)  # waiting time
    process_queue[i].append(0)  # turn around time
    process_queue[i].append(0)  # completion time
    print('')

process_queue.sort(key=lambda process_queue: process_queue[1])

for i in range(n):
    #to calculate completion time
    process_queue[i][5] +=process_queue[i][2]

    # calculate waiting time and turn around time
    process_queue[i][4] = process_queue[i][5] - process_queue[i][1]
    process_queue[i][3] = process_queue[i][4] - process_queue[i][2]

    # update total completion time
    total_ctime = process_queue[i][5]

print('ProcessName\tArrivalTime\tBurstTime\tWaitingTime\tTurnAroundTime\tCompletionTime')
for i in range(n):
    # print process details
    print(process_queue[i][0], '\t\t', process_queue[i][1], '\t\t', process_queue[i][2], '\t\t', process_queue[i][3],
          '\t\t', process_queue[i][4], '\t\t', process_queue[i][5])

print('Total waiting time: ', total_wtime)
print('Average waiting time: ', (total_wtime / n))
