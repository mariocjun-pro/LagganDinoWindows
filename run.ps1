$dir = Get-Location
Write-Host "Verificando se a pasta build existe..."
Test-Path $dir\build | Out-Null
if ($?) {
    Write-Host "existe, apagando..."
    Remove-Item -Path $dir\build -Recurse -Force | Out-Null
}

Write-Host "criando a pasta build..."
New-Item -ItemType Directory -Path $dir\build -Force | Out-Null

Write-Host "OK, pasta criada, entrando na pasta build..."
Set-Location $dir\build | Out-Null

Write-Host "Executando o cmake..."
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Debug

Write-Host "Executando o ninja..."
ninja

Write-Host "Executando LagganDino..."
Set-Location $dir\build
.\LagganDino.exe

Set-Location $dir | Out-Null

exit 0







