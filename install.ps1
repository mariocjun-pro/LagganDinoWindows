Write-Host "Verificando se chocolatey está instalado..."
if (Get-Command choco -ErrorAction SilentlyContinue) {
    Write-Host "chocolatey está instalado, pulando..."
}else {
    Write-Host "Chocolatey nao esta instalado. Instalando, aguarde..."
    Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iwr https://community.chocolatey.org/install.ps1 -UseBasicParsing | iex | Out-Null
}

RefreshEnv.cmd

Write-Host "Verificando se o cmake ver. 3.24.3 esta instalado..."
Test-Path $env:ChocolateyInstall\bin\cmake.exe | Out-Null
if ($? -eq $false) {
    Write-Host "cmake esta instalado, OK!"
} else {
    Write-Host "cmake nao esta instalado. Instalando, aguarde..."
    choco install cmake --version=3.24.3 --installargs 'ADD_CMAKE_TO_PATH=System' -y | Out-Null
}

RefreshEnv.cmd

Write-Host "Verificando se o ninja ver. 1.10.2 esta instalado..."
Test-Path $env:ChocolateyInstall\bin\ninja.exe | Out-Null
if ($? -eq $false) {
    Write-Host "ninja esta instalado, OK!"
} else {
    Write-Host "ninja nao esta instalado. Instalando, aguarde..."
    choco install ninja --version=1.10.2 --installargs 'ADD_CMAKE_TO_PATH=System' -y | Out-Null
}

RefreshEnv.cmd

Write-Host "Verificando se o mingw ver. 8.1.0 esta instalado..."
Test-Path $env:ChocolateyInstall\bin\mingw32-make.exe | Out-Null
if ($? -eq $false) {
    Write-Host "mingw esta instalado, OK!"
} else {
    Write-Host "mingw nao esta instalado. Instalando, aguarde..."
    choco install mingw --version=8.1.0 --installargs 'ADD_CMAKE_TO_PATH=System' -y | Out-Null
}

RefreshEnv.cmd

Write-Host "Dependencias instaladas, OK!, quer compilar o LagganDino agora? (s/n)"
$exec = Read-Host
if ($exec -eq "s") {
    Write-Host "Executando o LagganDino..."
    .\run.ps1
} else {
    Write-Host "OK, nao executando o LagganDino... Clique em qualquer tecla para sair..."
    Read-Host
}

exit 0