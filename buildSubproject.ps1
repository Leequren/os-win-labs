param (
    [string]$lab = "LAB1",
    [switch]$run
)

$buildDirectory = "./build"


try {
    if(Test-Path -Path $buildDirectory) {
        Write-Host "Directory already exists"
        Remove-Item -Path $buildDirectory -Recurse -Force
    }
    
    New-Item -Path $buildDirectory -ItemType Directory
    
    Set-Location -Path $buildDirectory
    
    $labToBuild = switch ($lab) {
        "LAB1" {"BUILD_LAB1=ON"}
        "LAB2" {"BUILD_LAB2=ON"}
        "LAB3" {"BUILD_LAB3=ON"}
        "LAB4" {"BUILD_LAB4=ON"}
        "LAB5" {"BUILD_LAB5=ON"}
        "LAB6" {"BUILD_LAB6=ON"}
        default {throw "Invalid lab specified"}
    }

    $runProgram = ""
    if($run -eq $false) {
        $runProgram = ""
    } else {
        $runProgram = "--target run"
    }
    
    cmake -G "MinGW Makefiles" -D $labToBuild  ..
    
    $buildArguments = @('.', $runProgram).Where({ $_ })  # Это удалит пустые строки из аргументов
    cmake --build $buildArguments

    # cmake --build . $runProgram
} finally {
    Set-Location -Path .. 
}



