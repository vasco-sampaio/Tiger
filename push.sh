if [ "$#" -lt 1 ]; then
    echo "Usage: ./push.sh [Commit message]"
    exit 1
fi

git add src lib tests
git commit -m "$1"

if [ "$#" -eq 2 ]; then
    git push origin $2
else
    git push
fi
