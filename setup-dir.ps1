<# 
.Description
A PowerShell Script to setup a new Section directory for this project
#>
param ([string] $Name="New Section", [string] $Com="n", [string] $Path=".")

Write-Host "Running new dir setup..." -fore yellow

New-Item -Path $Path -Name $Name -ItemType "directory" | Out-Null
Set-Location $Path\$Name  | Out-Null

New-Item -Path . -Name "bin" -ItemType "directory" | Out-Null
New-Item -Path . -Name ".gitignore" -Itemtype "File" | Out-Null
# New-Item -Path . -Name "run.ps1" -ItemType "File" | Out-Null

Write-Output "/*.exe" "/*.out" | Out-File -FilePath ./.gitignore | Out-Null
Set-Location ./bin | Out-Null

Write-Host "Created new directory '$($Name) in $($Path)\'" -fore green
Write-Host "Created file .gitignore in $($Path)\$($Name)\" -fore green

if ($Com -eq "y") {
    $Msg = "Create $($Name) directory"
    git add . | Out-Null
    git commit -m $Msg | Write-Host
    git push origin master | Write-Host
    Write-Host "Committed to Git and pushed to remote 'origin' with commit message:", $Msg -fore blue
}

Write-Host "Done!" -fore green