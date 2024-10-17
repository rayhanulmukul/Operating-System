read -p "Enter a number: " n
if (( n%3 == 0 )) && (( n%5 == 0 ))
then echo $n is divisible by both 3 and 5
else echo $n is not divisible by both 3 and 5
fi

