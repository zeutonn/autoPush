#!/bin/bash

# Get the current working directory
current_dir=$(pwd)

# Get the name of the GitHub repo
repo_name="autoPush"

# Get the path to the folder that contains the files to be pushed
files_dir="/home/zeuton/CODES/autoPush"

# Check if the GitHub repo exists
if ! git ls-remote https://github.com/zeutonn/autoPush.git > /dev/null; then
  echo "The GitHub repo autoPush does not exist."
  exit 1
fi


# Check if the folder that contains the files to be pushed exists
if ! [ -d "/home/zeuton/CODES/autoPush" ]; then
  echo "The folder $autoPush does not exist."
  exit 1
fi

# Push the files to the GitHub repo
git add "$files_dir"
git commit -m "Automated push of files to GitHub"
git push https://github.com/zeutonn/autoPush.git

# Exit with success
exit 0
