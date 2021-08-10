param ([string]$name="New Section", [string]$com="n")

Write-Host "Running new dir setup..." -fore yellow

mkdir ./$name | Out-Null
cd ./$name | Out-Null
mkdir ./bin | Out-Null
touch ./.gitignore | Out-Null
echo "/*.exe" >> ./.gitignore | Out-Null
echo "/*.out" >> ./.gitignore | Out-Null

Write-Host "Created new directory '" $name "'" -fore green
Write-Host "Created file .gitignore in" $name -fore green

if ($com -eq "y") {
    $msg = "Create" $name "directory"
    git add . | Out-Null
    git commit -m $msg | Write-Host
    git push origin master | Write-Host
}

Write-Host "Done!" -fire green
