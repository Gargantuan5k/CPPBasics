param ([string]$name="New Section", [string]$com="n")

Write-Host "Running new dir setup..."

mkdir ./$name | Out-Null
cd ./$name | Out-Null
mkdir ./bin | Out-Null
touch ./.gitignore | Out-Null
echo "/*.exe" >> ./.gitignore | Out-Null
echo "/*.out" >> ./.gitignore | Out-Null

Write-Host "Created new directory '" $name "'"
Write-Host "Created file .gitignore in" $name

if ($com -eq "y") {
    $msg = "Create" $name "directory"
    git add . | Out-Null
    git commit -m $msg
    git push origin master
}

Write-Host "Done!"
