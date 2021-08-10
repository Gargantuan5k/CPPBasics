param ([string]$m="Commit to git")

Write-Host "X---------------------------------------------------------------------X"
Write-Host "Running git commit & push script"
Write-Host "X---------------------------------------------------------------------X"

git add . | Write-Host
git commit -m $m | Write-Host
git push origin master | Write-Host

Write-Host "X---------------------------------------------------------------------X"
Write-Host "Done!"
Write-Host "X---------------------------------------------------------------------X"