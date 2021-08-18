<# .Description
A Script to automate committing files to Git & pushing to remote
#>

param ([string] $m="Commit to Git")

Write-Host "Git Commit Script Running..." -fore yellow
Write-Host ""

git add . | Write-Host
git commit -m $m | Write-Host
git push origin master | Write-Host

Write-Host ""
Write-Host "Done!" -fore green