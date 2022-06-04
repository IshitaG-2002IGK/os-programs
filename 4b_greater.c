echo "Enter A" 
read a 
echo "Enter B" 
read b 
echo "Enter C" 
read c 
if [ $a -gt $b -a $a -gt $c ] 
then 
echo "A is greater" 
elif [ $b -gt $a -a $b -gt $c ] 
then 
echo "B is greater" 
else 
echo "C is greater" 
fi 
