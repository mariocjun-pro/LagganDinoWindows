Install-Module -Name WriteAscii -Force
Import-Module WriteAscii
Write-Host "====================================================================================="
Write-Ascii "LagganDino" -fore rainbow

$dir = Get-Location
Write-Host "====================================================================================="
Write-Host "|> Diretorio atual: $dir"

Write-Host "====================================================================================="
Write-Host "|> Verificando se a pasta build existe..."
Test-Path $dir\build | Out-Null
if ($?) {
    Write-Host "====================================================================================="
    Write-Host "|> A pasta build existe, removendo..."
    Remove-Item -Path $dir\build -Recurse -Force | Out-Null
}

Write-Host "====================================================================================="
Write-Host "|> Re-criando a pasta build..."
New-Item -ItemType Directory -Path $dir\build -Force | Out-Null

Write-Host "====================================================================================="
Write-Host "|> OK, pasta criada, entrando na pasta build..."
Set-Location $dir\build | Out-Null

Write-Host "====================================================================================="
Write-Host "|> Executando o cmake..."
Write-Host "====================================================================================="
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Debug

Write-Host "====================================================================================="
Write-Host "|> Executando o ninja..."
Write-Host "====================================================================================="
ninja

Write-Host "====================================================================================="
Write-Host "|> Executando LagganDino, Bom jogo!"
Write-Host "====================================================================================="
Set-Location $dir\build
#.\LagganDino.exe

Set-Location $dir | Out-Null

exit 0







