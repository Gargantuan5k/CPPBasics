Write-Host "Running git commit & push script"

param ([string]$m = "Commit to git")

git add .
git commit -m $m
git push origin master

Write-Host "Done!"