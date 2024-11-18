#!/bin/bash

points=0

# Level 1
ran=$(( $RANDOM % 2 ))
echo "Level 1. Select number between 0-1"
read num
if [[ $ran == $num ]]; then
	points=$((points+1))
	echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 2
ran=$(( $RANDOM % 5 ))
echo "Level 2. Select number between 0-4"
read num
if [[ $ran == $num ]]; then
	points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 3
ran=$(( $RANDOM % 9 ))
echo "Level 3. Select number between 0-8"
read num
if [[ $ran == $num ]]; then
	points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 4
ran=$(( $RANDOM % 13 ))
echo "Level 4. Select number between 0-12"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 5
ran=$(( $RANDOM % 17 ))
echo "Level 5. Select number between 0-16"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 6
ran=$(( $RANDOM % 21 ))
echo "Level 6. Select number between 0-20"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
        exit 1
fi

# Level 7
ran=$(( $RANDOM % 25 ))
echo "Level 7. Select number between 0-24"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 8
ran=$(( $RANDOM % 29 ))
echo "Level 8. Select number between 0-28"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 9
ran=$(( $RANDOM % 33 ))
echo "Level 9. Select number between 0-32"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi

# Level 10
ran=$(( $RANDOM % 37 ))
echo "Level 10. Select number between 0-36"
read num
if [[ $ran == $num ]]; then
        points=$((points+1))
        echo "Good! Score: $points"
else
        echo "Bad! Score: $points"
	exit 1
fi
