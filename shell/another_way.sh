read a b
if (( $a > $b ))
then 
    echo a is greater than b
elif (( $a < $b )) 
then 
    echo a is less than b
else echo a and b are equal
fi

sum=$((20 + 1))
echo $sum

read -p "Enter a number: " n
if (( n%2 == 1 )) || (( $n <= 100))
then echo $n is odd
else echo $n is even
fi