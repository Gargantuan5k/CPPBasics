param ([string]$name="New Section")

Write-Host "Running new dir setup..."

mkdir ./$name | Out-Null
cd ./$name | Out-Null
touch ./.gitignore | Out-Null
echo "/*.exe" >> ./.gitignore | Out-Null
echo "/*.out" >> ./.gitignore | Out-Null

Write-Host "Created new directory " + $name
Write-Host "Created file .gitignore in " $name

Write-Host "Done!"
