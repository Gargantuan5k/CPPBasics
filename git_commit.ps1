param ([string] $m="Commit to git")

Write-Host "Git Commit Script Running..." -fore yellow
Write-Host ""

git add . | Write-Host -fore blue
git commit -m $m | Write-Host -fore blue
git push origin master | Write-Host -fore blue

Write-Host ""
Write-Host "Done!" -fore green