if [ "$#" -ne 1 ]; then
    echo "Usage: ./push.sh [Commit message]"
    exit 1
fi

git add src lib tests
git commit -m "$1"
git push
