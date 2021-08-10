param ([string]$m="Commit to git")

Write-Host "Git Commit Script Running..."
Write-Host ""

git add . | Write-Host
git commit -m $m | Write-Host
git push origin master | Write-Host

Write-Host ""
Write-Host "Done"