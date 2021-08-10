param ([string]$m = "Commit to git")

Write-Host "Running git commit & push script"

git add .
git commit -m $m
git push origin master

Write-Host "Done!"