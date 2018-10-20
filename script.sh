#! /bin/bash
cc generate_data.c -o generate_data && ./generate_data

echo "Single thread program started at : $(date +"%T")"
start=$(date +"%s")
cc prog1.c -o prog1 && ./prog1
end=$(date +"%s")
echo "Single thread program ended at : $(date +"%T")"
diff=$(($end-$start))
echo "Time taken by single threaded program is $diff seconds"

echo "Multi thread program started at : $(date +"%T")"
start=$(date +"%s")
cc prog2.c -pthread -w -o prog2 && ./prog2
end=$(date +"%s")
echo "Multi thread program ended at : $(date +"%T")"
diff=$(($end-$start))
echo "Time taken by multithreaded program is $diff seconds"
