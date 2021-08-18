<# 
.Description
A PowerShell Script to setup a new Section directory for this project
#>
param ([string] $name="New Section", [string] $com="n", [string] $path=".")


Write-Host "Running new dir setup..." -fore yellow

New-Item -Path $path -Name $name -ItemType "directory" | Out-Null
Set-Location $path\$name  | Out-Null
New-Item -Path . -Name "bin" -ItemType "directory" | Out-Null
New-Item -Path . -Name ".gitignore" -Itemtype "File" | Out-Null
Write-Output "/*.exe" >> ./.gitignore | Out-Null
Write-Output "/*.out" >> ./.gitignore | Out-Null
Set-Location ./.. | Out-Null

Write-Host "Created new directory '"$name"'" -fore green
Write-Host "Created file .gitignore in", $name -fore green

if ($com -eq "y") {
    $msg = "Create", $name, "directory"
    git add . | Out-Null
    git commit -m $msg | Write-Host
    git push origin master | Write-Host
    Write-Host "Committed to Git:", $msg -fore blue
}

Write-Host "Done!" -fore green
