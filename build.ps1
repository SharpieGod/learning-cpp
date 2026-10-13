# basic build script (Windows version of ./build)

$ErrorActionPreference = "Stop"

if ($args.Count -lt 1) {
    Write-Error "Usage: .\build.ps1 <file.cpp> [args...]"
    exit 1
}

$src = $args[0]
$rest = @($args | Select-Object -Skip 1)

if (-not (Test-Path -PathType Leaf $src)) {
    Write-Error "error: no such file: $src"
    exit 1
}

$builddir = Join-Path $HOME ".cpp\build"
New-Item -ItemType Directory -Force $builddir | Out-Null

$bin = Join-Path $builddir ([IO.Path]::GetFileNameWithoutExtension($src) + ".exe")

g++ -O2 -std=c++17 -static -o $bin $src
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

if ($MyInvocation.ExpectingInput) {
    $input | & $bin @rest
} else {
    & $bin @rest
}
exit $LASTEXITCODE
