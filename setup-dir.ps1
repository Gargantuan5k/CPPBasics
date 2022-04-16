<# 
.Description
A PowerShell Script to setup a new Section directory for this project
#>
param ([string] $Name="New Section", [switch] $Commit, [switch] $Push, [string] $Path=".")

$l = (Get-Location).Path

Write-Host "Running setup for new directory..." -fore yellow

New-Item -Path $Path -Name $Name -ItemType "Directory" | Out-Null
Set-Location $Path\$Name  | Out-Null

New-Item -Path . -Name "bin" -ItemType "Directory" | Out-Null
New-Item -Path . -Name ".gitignore" -Itemtype "File" | Out-Null
New-Item -Path .\bin -Name "debug" -Itemtype "Directory" | Out-Null
# New-Item -Path . -Name "run.ps1" -ItemType "File" | Out-Null

Write-Output "/*.exe" "/*.out" | Out-File -FilePath ./.gitignore | Out-Null
Set-Location ./bin | Out-Null

Write-Host "Created new directory '$($Name) in $($Path)\'" -fore green
Write-Host "Created file .gitignore in $($Path)\$($Name)\" -fore green

if ($Commit) {
    Set-Location $($l)
    $Msg = "Create $($Name) directory"
    git add "$($Path)/$($Name)/" | Out-Null
    git commit -m $Msg | Write-Host
    Write-Host "Committed changes to Git with message:", $Msg -fore blue

    if ($Push) {
        git push origin master | Write-Host
        Write-Host "Pushed committed changes to remote repository" -fore blue
    }
}

Write-Host "Done!" -fore green