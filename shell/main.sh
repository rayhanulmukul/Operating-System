# i=1
# while(( i <= 10))
# do
#     # echo $i
#     i=$(( $i + 1))
# done

# for(( n=0; n <= 10; n++))
# do
#     # echo $n
# done

arr=( )
read -p "Enter the number of elements: " n
for(( i=0; i<n; i++))
do
    read arr[$i]
done
echo print array
for(( i=0;i<n; i++))
do
    echo ${arr[$i]}
done

echo ${#arr[@]}