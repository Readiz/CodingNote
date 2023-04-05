const glob = require('glob-promise');
const fse = require('fs-extra');

const writeFileSync = (filepath, str) => {
    try {
        fse.outputFile(filepath, str);
    } catch (e) {
        console.error('Writing Error', filepath);
    }
}

(async () => {
    let paths = await glob.promise('./**/*.cpp', {});
    paths = paths.map(item => encodeURI(item));
    console.log(paths);
    writeFileSync('./output/sourceFileList.json', JSON.stringify(paths, null, 2));
    writeFileSync('./output/lastUpdated.txt', String(new Date()));
})();
