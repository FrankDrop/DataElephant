function checkMex()
    [md5_path,~,~] = fileparts(which('CalcMD5.c'));

    if ispc
        if ~exist([md5_path '/CalcMD5.mexw64'],'file')
            fprintf('This is probably the first time you run DataElephant on a Windows system. Mexing the CalcMD5 function.\n');
            mex([md5_path '/CalcMD5.c'],'-largeArrayDims','-outdir', md5_path);
        end
    else
        if ~exist([md5_path '/CalcMD5.mexa64'],'file')
            fprintf('This is probably the first time you run DataElephant on a Unix system. Mexing the CalcMD5 function.\n');
            mex([md5_path '/CalcMD5.c'],'-largeArrayDims','CFLAGS="$CFLAGS -std=c99"','-outdir', md5_path);
        end
    end
end

